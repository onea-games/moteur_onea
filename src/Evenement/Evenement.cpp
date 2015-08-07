#include "Evenement.hpp"

onea::evenement::Input::Input(sf::Window *fenetre)
    : m_fenetre(fenetre),
      m_clock(),
      m_event(),
      m_x(0),
      m_y(0),
      m_xRel(0),
      m_yRel(0),
      m_terminer(false),
      m_stackInput(MAX_STACK)
{
    for( int i = 0; i < sf::Keyboard::KeyCount; ++i )
        m_touches[i] = false;

    for( int i = 0; i < sf::Mouse::ButtonCount; ++i )
        m_boutonsSouris[i] = false;

    sf::Joystick::update();

    for( int i = 0; i < sf::Joystick::Count; ++i ){
        m_joysticks[i].id = 0;
        if( sf::Joystick::isConnected(i) )
            m_joysticks[i].connected = true;
        for( int j = 0; j < sf::Joystick::ButtonCount; ++j )
            m_joysticks[i].boutons[j] = false;
    }
}

onea::evenement::Input::~Input()
{
}

void onea::evenement::Input::updateEvenements()
{
    m_xRel = 0;
    m_yRel = 0;

    while( m_fenetre->pollEvent( m_event ) ){

        switch (m_event.type) {

        // Clavier
        case sf::Event::KeyPressed:
            if( !m_touches[m_event.key.code] ) addStack(Clavier, m_event.key.code, m_clock.getElapsedTime().asSeconds());
            m_touches[m_event.key.code] = true;
            break;

        case sf::Event::KeyReleased:
            m_touches[m_event.key.code] = false;
            break;

        // Souris
        case sf::Event::MouseButtonPressed:
            if( !m_boutonsSouris[m_event.mouseButton.button] ) addStack(Souris, m_event.mouseButton.button, m_clock.getElapsedTime().asSeconds());
            m_boutonsSouris[m_event.mouseButton.button] = true;
            break;

        case sf::Event::MouseButtonReleased:
            m_boutonsSouris[m_event.mouseButton.button] = false;
            break;

        case sf::Event::MouseMoved:
            m_xRel = m_x - m_event.mouseMove.x;
            m_yRel = m_y - m_event.mouseMove.y;
            m_x = m_event.mouseMove.x;
            m_y = m_event.mouseMove.y;
            break;

        // Joystick
        case sf::Event::JoystickButtonPressed:
            if( !m_joysticks[m_event.joystickButton.joystickId].boutons[m_event.joystickButton.button] )
                addStack(Joystick, m_event.joystickButton.button, m_clock.getElapsedTime().asSeconds(), m_event.joystickButton.joystickId);
            m_joysticks[m_event.joystickButton.joystickId].boutons[m_event.joystickButton.button] = true;
            break;

        case sf::Event::JoystickButtonReleased:
            m_joysticks[m_event.joystickButton.joystickId].boutons[m_event.joystickButton.button] = false;
            break;

        case sf::Event::JoystickMoved:
            m_joysticks[m_event.joystickMove.joystickId].stick[m_event.joystickMove.axis] = m_event.joystickMove.position;
            break;

        // Fenêtre
        case sf::Event::Closed:
            m_terminer = true;
            break;

        default:
            break;
        }

    }
}

bool onea::evenement::Input::terminer() const
{
    return m_terminer;
}

bool onea::evenement::Input::touche(sf::Keyboard::Key touche) const
{
    return m_touches[touche];
}

bool onea::evenement::Input::boutonSouris(sf::Mouse::Button bouton) const
{
    return m_boutonsSouris[bouton];
}

sf::Vector2f onea::evenement::Input::sourisPosition() const
{
    return sf::Vector2f(m_x, m_y);
}

bool onea::evenement::Input::sourisBouger() const
{
    if( m_xRel == 0 && m_yRel == 0 )
        return true;
    else
        return false;
}

void onea::evenement::Input::afficherSouris(bool visible)
{
    m_fenetre->setMouseCursorVisible(visible);
}

bool onea::evenement::Input::toucheJoystick(unsigned int id, unsigned int button) const
{
    if( id < sf::Joystick::Count && button < sf::Joystick::ButtonCount )
        return m_joysticks[id].boutons[button];
    else
        return false;
}

unsigned int onea::evenement::Input::axeJoystick(int id, sf::Joystick::Axis axe) const
{
    if( id < sf::Joystick::Count )
        return m_joysticks[id].stick[axe];
    else
        return 0;
}

void onea::evenement::Input::setSeuilJoystick(float seuil)
{
    if( m_fenetre != 0 )
        m_fenetre->setJoystickThreshold(seuil);
}

void onea::evenement::Input::addStack(typeEvent type, unsigned int code, float temps, unsigned int idJoy)
{
    evenementStock e;
    e.type = type;
    e.code = code;
    e.tempsCommencement = temps;
    e.idJoy = idJoy;

    m_stackInput.push(e);
}

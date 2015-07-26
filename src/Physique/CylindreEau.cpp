#include "CylindreEau.hpp"

onea::physique::CylindreEau::CylindreEau(Vector2f position, float hauteurEcran)
    : m_position(position),
      m_hauteur(hauteurEcran),
      m_hauteurInit(m_hauteur - m_position.y),
      m_vitesse(0),
      m_vertices(Lines, 2)
{
    // 0 Surface
    // 1 fond

    m_vertices[0].position = position;

    m_vertices[1].position.x = m_position.x;
    m_vertices[1].position.y = m_hauteur;

    cout << m_hauteurInit << endl;
}

void onea::physique::CylindreEau::update()
{
    const float k = 0.025f; // adjust this value to your liking

    m_hauteur = m_position.y;

    float x = m_hauteur - m_hauteurInit;
    float acceleration = - k * x - 0.025f * m_vitesse;

    if( Keyboard::isKeyPressed( Keyboard::Space ) )
        acceleration -= 1;

    m_position.y += m_vitesse;
    m_vitesse += acceleration;

    m_vertices[0].position = m_position;

    cout << m_position.y << endl;

    string test;

    //cin >> test;
}

void onea::physique::CylindreEau::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(m_vertices, states);
}

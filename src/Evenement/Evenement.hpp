#ifndef EVENEMENT_HPP
#define EVENEMENT_HPP

#define MAX_STACK 1000

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Joystick.hpp>

#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

#include "../Stack.cpp"

namespace onea
{
    namespace evenement
    {

        class Input
        {
        public:
            enum typeEvent{
                Clavier,
                Souris,
                Joystick
            };

            typedef struct evenementStock{
                typeEvent type;
                unsigned int idJoy;
                unsigned int code;
                float tempsCommencement;
            } evenementStock;

        public:
            Input( sf::Window *fenetre );
            ~Input();

            void updateEvenements();
            bool terminer() const;
            bool touche(sf::Keyboard::Key touche) const;
            bool boutonSouris( sf::Mouse::Button bouton ) const;
            sf::Vector2f sourisPosition() const;
            bool sourisBouger() const;
            void afficherSouris(bool visible);
            bool toucheJoystick(unsigned int id, unsigned int button) const;
            unsigned int axeJoystick(int id, sf::Joystick::Axis axe) const;
            void setSeuilJoystick(float seuil);
        protected:
            typedef struct joystick{
                int id;
                bool connected;
                bool boutons[sf::Joystick::ButtonCount];
                int stick[sf::Joystick::AxisCount];
            } joystick;

            void addStack( typeEvent type, unsigned int code, float temps, unsigned int idJoy = 0 );

            sf::Window *m_fenetre;
            sf::Clock m_clock;

            sf::Event m_event;
            bool m_touches[sf::Keyboard::KeyCount];
            bool m_boutonsSouris[sf::Mouse::ButtonCount];

            // Souris
            int m_x, m_y, m_xRel, m_yRel;

            // Joystick
            joystick m_joysticks[sf::Joystick::Count];

            bool m_terminer; // Terminer la bouche principale ( EX: EventCloseWindow )

            // Stack
            onea::Stack<evenementStock> m_stackInput;
        };
    }
}

#endif // EVENEMENT_HPP

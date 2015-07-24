#ifndef CYLINDREEAU_HPP
#define CYLINDREEAU_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

namespace onea
{
    namespace physique
    {
        class CylindreEau : public Drawable
        {
        public:
            CylindreEau( Vector2f position, float hauteurEcran );

            void update();

        protected:
            void draw(RenderTarget &target, RenderStates states) const;

            Vector2f m_position;
            float m_hauteur; // Hauteur de l'écran
            float m_hauteurInit; // Hauteur sans compression ni étirement
            float m_vitesse;

            VertexArray m_vertices;
        };
    }
}

#endif // CYLINDREEAU_HPP

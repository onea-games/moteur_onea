#ifndef ENTITE_H
#define ENTITE_H

#include <SFML/Graphics.hpp>

#include "RectangleShape.hpp"

using namespace sf;
using namespace std;

namespace onea
{

    enum Direction
    {
        HAUT,
        HAUT_DROIT,
        DROIT,
        DROIT_BAS,
        BAS,
        BAS_GAUCHE,
        GAUCHE,
        GAUCHE_HAUT
    };

    class Entite
    {

    public:
        Entite( Vector2f position = Vector2f(), Vector2f taille = Vector2f(), Direction dir = BAS, float vitesse = 0 );

        bool collision( Entite &entite ) const;

        void bouger(float x, float y);
        void bouger(Vector2f &pos);

        const Vector2f &position() const;

        Direction direction();

        const Vector2f &taille() const;
        void taille( const Vector2f &taille);

        const vector< LigneShape<float> > &getLigneShape() const;
    protected:
        FloatRectangleShape m_bound;
        Vector2f m_position, m_futurePosition;
        float m_vitesse;
        Direction m_direction;
        Vector2f m_taille;
    };

}

#endif // ENTITE_H

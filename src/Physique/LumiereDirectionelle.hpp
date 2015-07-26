#ifndef LUMIEREDIRECTIONELLE_HPP
#define LUMIEREDIRECTIONELLE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

#include "Lumiere.hpp"

using namespace sf;
using namespace std;

namespace onea
{

namespace physique
{

    class LumiereDirectionelle : public Lumiere
    {
    public:
        LumiereDirectionelle( Vector2f position, float intensite, float rayon, float angle, float angleOuverture, Color couleur );

        void Generate( vector< LigneShape<float> > &vec );

        void setAngle( float angle );
        float getAngle() const;

        void setAngleOuverture( float angleOuverture );
        float getAngleOuverture() const;
    protected:
        float m_angle;
        float m_angleOuverture;
    };

}

}

#endif // LUMIEREDIRECTIONELLE_HPP

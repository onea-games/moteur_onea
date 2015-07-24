#include "LumiereDirectionelle.hpp"


onea::physique::LumiereDirectionelle::LumiereDirectionelle( Vector2f position, float intensite, float rayon, float angle, float angleOuverture, Color couleur )
    : onea::Lumiere(position, intensite, rayon, 1, couleur),
      m_angle(angle),
      m_angleOuverture(angleOuverture)
{
}

void onea::physique::LumiereDirectionelle::Generate( vector< LigneShape<float> > &vec )
{
    m_shape.clear();

    float angle = m_angle * M_PI / 180;
    float o_angle = m_angleOuverture * M_PI / 180;

    AddTriangle( Vector2f( (m_rayon * cos(angle + o_angle * 0.5)), (m_rayon * sin(angle + o_angle * 0.5)) ),
                Vector2f( (m_rayon * cos(angle - o_angle * 0.5)), (m_rayon * sin(angle - o_angle * 0.5)) ), 0, vec );
}

void onea::physique::LumiereDirectionelle::setAngle( float angle )
{
    m_angle = angle;
}

float onea::physique::LumiereDirectionelle::getAngle() const
{
    return m_angle;
}

void onea::physique::LumiereDirectionelle::setAngleOuverture( float angleOuverture )
{
    m_angleOuverture = angleOuverture;
}

float onea::physique::LumiereDirectionelle::getAngleOuverture() const
{
    return m_angleOuverture;
}

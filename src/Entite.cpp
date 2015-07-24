#include "Entite.hpp"

onea::Entite::Entite(Vector2f position, Vector2f taille, Direction dir, float vitesse)
    : m_bound(position, taille),
      m_position(position),
      m_futurePosition(position),
      m_vitesse(vitesse),
      m_direction(dir),
      m_taille(taille)
{
}

bool  onea::Entite::collision( Entite &entite ) const
{
    return false; // A finir car j'ai la flemme ( il est 3h00 du mat' )
}

void onea::Entite::bouger( float x, float y )
{
    m_position.x = x;
    m_position.y = y;
}

void onea::Entite::bouger(Vector2f &pos)
{
    m_position = pos;
}

const Vector2f &onea::Entite::position() const
{
    return m_position;
}

const Vector2f &onea::Entite::taille() const
{
    return m_taille;
}

void onea::Entite::taille( const Vector2f &taille )
{
    m_taille = taille;
}

const vector< onea::LigneShape<float> > &onea::Entite::getLigneShape() const
{
    return m_bound.getLigneShape();
}

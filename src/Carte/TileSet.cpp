#include "TileSet.hpp"

onea::carte::TileSet::TileSet(sf::Texture *texture, sf::Vector2f tailleTile)
    : onea::Entite( Vector2f(), (sf::Vector2f)texture->getSize() ),
      m_tailleTile(tailleTile),
      m_tiles(),
      m_nombreLargeur(m_taille.x/m_tailleTile.x),
      m_nombreHauteur(m_taille.y/m_tailleTile.y)
{
    for( size_t i(0); i < m_nombreLargeur; ++i ){

        for( size_t j(0); j < m_nombreHauteur; ++j ){

            m_tiles.push_back( onea::carte::Tile(texture,
                                                 sf::Vector2f( i * m_tailleTile.x, j * m_tailleTile.y ),
                                                 sf::Vector2f(),
                                                 m_tailleTile
                                                 ) );

        }

    }
}

onea::carte::Tile onea::carte::TileSet::getTile( float x, float y )
{
    if( x < m_nombreLargeur && y < m_nombreHauteur ){
        return m_tiles[y*m_nombreLargeur +  x];
    } else
        return onea::carte::Tile();
}

onea::carte::Tile onea::carte::TileSet::getTile( sf::Vector2f pos )
{
    return getTile(pos.x, pos.y);
}

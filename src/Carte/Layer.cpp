#include "Layer.hpp"

#include <iostream>

onea::carte::Layer::Layer(sf::Vector2f position, sf::Vector2f tailleTile)
    : m_tiles()
{
}

void onea::carte::Layer::addTile(float x, float y, Tile &tile)
{
    onea::carte::tilePosition t( tile, sf::Vector2f( x * m_tailleTile.x, y * m_tailleTile.y ) );

    m_tiles.push_back( t );
}

void onea::carte::Layer::addTile(sf::Vector2f position, Tile &tile)
{
    addTile( position.x, position.y, tile );
}

bool onea::carte::Layer::delTile(float x, float y)
{
    std::vector<onea::carte::tilePosition>::iterator i = m_tiles.begin();
    for( ; i != m_tiles.end(); ++i ){
        if( (*i).positionAbs.x == x * m_tailleTile.x && (*i).positionAbs.y == y * m_tailleTile.y ){
            m_tiles.erase(i);
            return true;
        }
    }

    return false;
}

void onea::carte::Layer::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
    std::vector<onea::carte::tilePosition>::const_iterator i = m_tiles.begin();

    std::cout << m_tiles[0].positionAbs.y << endl;

    for(; i != m_tiles.end(); ++i)
        target.draw((*i).tile, states);
}

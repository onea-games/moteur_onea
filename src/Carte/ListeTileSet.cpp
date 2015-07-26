#include "ListeTileSet.hpp"

onea::carte::ListeTileSet::ListeTileSet()
    : onea::carte::Liste<onea::carte::TileSetLoader>::Liste<onea::carte::TileSetLoader>()
{
}

void onea::carte::ListeTileSet::add(unsigned int id, sf::Texture *texture, sf::Vector2f tailleTile)
{
    onea::carte::TileSetLoader tileset("", id, texture, tailleTile);

    m_type.insert( tileset );
}

void onea::carte::ListeTileSet::add(unsigned int id){}

bool onea::carte::ListeTileSet::del(unsigned int id)
{

    for( set<onea::carte::TileSetLoader>::const_iterator p = m_type.begin();
    p != m_type.end(); ++p ){

        if( (*p).id == id ){
            m_type.erase( p );
            return true;
        } else if( (*p).id > id )
            return false;

    }

    return false;
}

const onea::carte::TileSet *onea::carte::ListeTileSet::get(unsigned int id)
{
    for( set<onea::carte::TileSetLoader>::const_iterator p = m_type.begin();
    p != m_type.end(); ++p ){

        if( (*p).id == id ){
            return &(*p).tileset;
        } else if( (*p).id > id )
            return 0;

    }

    return 0;
}

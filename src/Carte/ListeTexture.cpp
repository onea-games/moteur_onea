#include "ListeTexture.hpp"

onea::carte::ListeTexture::ListeTexture()
    : onea::carte::Liste<onea::carte::TextureLoader>::Liste<onea::carte::TextureLoader>()
{
}

void onea::carte::ListeTexture::add( string nom, unsigned int id )
{
    TextureLoader texture( nom, id );

    m_type.insert( texture );
}

void onea::carte::ListeTexture::add( unsigned int id )
{
    onea::carte::TextureLoader texture("", id);

    m_type.insert( texture );
}

bool onea::carte::ListeTexture::del( unsigned int id )
{

    for( set<TextureLoader>::const_iterator p = m_type.begin();
    p != m_type.end(); ++p ){

        if( (*p).id == id ){
            m_type.erase( p );
            return true;
        } else if( (*p).id > id )
            return false;

    }

    return false;
}

const Texture *onea::carte::ListeTexture::get(unsigned int id) const
{

    for( set<TextureLoader>::const_iterator p = m_type.begin();
    p != m_type.end(); ++p ){

        if( (*p).id == id ){
            return &(*p).texture;
        } else if( (*p).id > id )
            return 0;

    }

    return 0;
}

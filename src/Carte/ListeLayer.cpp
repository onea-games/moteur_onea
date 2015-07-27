#include "ListeLayer.hpp"

onea::carte::ListeLayer::ListeLayer()
    : Liste()
{
}

void onea::carte::ListeLayer::add( unsigned int id, onea::carte::Layer &layer )
{
    onea::carte::LayerLoader t(id, layer);

    m_type.insert( t );
}

bool onea::carte::ListeLayer::del(unsigned int id)
{
    for( set<onea::carte::LayerLoader>::const_iterator p = m_type.begin();
    p != m_type.end(); ++p ){

        if( (*p).id == id ){
            m_type.erase( p );
            return true;
        } else if( (*p).id > id )
            return false;

    }

    return false;
}

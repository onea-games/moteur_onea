#include "TileSetLoader.hpp"

onea::carte::TileSetLoader::TileSetLoader(TiXmlDocument *document, TextureLoader *texLoad)
    : Loader(document, "tileSet"),
      m_texLoad(texLoad)
{
}

bool onea::carte::TileSetLoader::load()
{
    TiXmlHandle handle(m_document);
    TiXmlElement *elm = handle.FirstChildElement().FirstChildElement().Element();

    while( elm ){

        if( elm->Value() == m_nomBalise ){
            tilesetLoader l;
            int id;
            int idTexture;
            sf::Vector2u taille;

            if( elm->QueryIntAttribute("id", &id) == TIXML_SUCCESS ){

                if( elm->QueryIntAttribute("idTexture", &idTexture) == TIXML_SUCCESS ){

                    if( elm->QueryUnsignedAttribute("largeur", &taille.x) == TIXML_SUCCESS ){

                        if( elm->QueryUnsignedAttribute("hauteur", &taille.y) == TIXML_SUCCESS ){

                            if( (unsigned int)idTexture < m_texLoad->getVector().size() ){

                                l.tileset = new TileSet( &m_texLoad->getVector()[idTexture].texture, taille );
                                l.tileset->load();

                                l.id = id;

                                m_cont.push_back( l );
                            }

                        }

                    }

                }

            }
        }

        elm = elm->NextSiblingElement();
    }

    return true;
}

vector<onea::carte::tilesetLoader> &onea::carte::TileSetLoader::getVector()
{
    return m_cont;
}

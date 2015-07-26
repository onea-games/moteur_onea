#include "MapLoader.hpp"

onea::carte::MapLoader::MapLoader(std::string nomFichier)
    : m_document(nomFichier),
      m_textures(),
      m_lecture(false)
{
    if( !m_document.LoadFile() ){
        std::cerr << "Impossible de lire le document" << std::endl;
        std::cerr << "error #" << m_document.ErrorId() << " : " << m_document.ErrorDesc() << std::endl;
    }else
        m_lecture = true;
}

void onea::carte::MapLoader::load()
{
    if( m_lecture )
        loadTexture();
}

bool onea::carte::MapLoader::verifDocument()
{
    TiXmlHandle hd1(&m_document);
    TiXmlElement *elm = hd1.FirstChildElement().Element();

    if( std::string(elm->Value()) != "carte" )
        return true;
    else return false;
}

void onea::carte::MapLoader::loadTexture()
{
    TiXmlHandle hd( &m_document );
    TiXmlElement *elm = hd.FirstChildElement().FirstChildElement().Element();

    while( elm ){

        if( std::string(elm->Value()) == "texture" ){

            std::string nomFichier( elm->Attribute("fichier") );
            int id(0);

            elm->QueryIntAttribute("id", &id);

            m_textures.add( nomFichier, (unsigned int)id );

            elm = elm->NextSiblingElement();
        }

    }
}


void onea::carte::MapLoader::loadTileSet()
{
    TiXmlHandle hd( &m_document );
    TiXmlElement *elm = hd.FirstChildElement().FirstChildElement().Element();

    while( elm ){

        if( std::string(elm->Value()) == "tileSet" ){

            int idTile(0), idTexture=(0),
                largeurTile(0), hauteurTile(0);

            elm->QueryIntAttribute("id", &idTile);
            elm->QueryIntAttribute("idTexture", &idTexture);
            elm->QueryIntAttribute("largeurTile", &largeurTile);
            elm->QueryIntAttribute("hauteurTile", &hauteurTile);



        }

        elm = elm->NextSiblingElement();
    }
}

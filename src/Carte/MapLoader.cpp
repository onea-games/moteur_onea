#include "MapLoader.hpp"

onea::carte::MapLoader::MapLoader(string nomFichier)
    : m_document(nomFichier),
      m_textures(),
      m_lecture(false)
{
    cout << nomFichier << endl;

    if( !m_document.LoadFile() ){
        cerr << "Impossible de lire le document" << endl;
        cerr << "error #" << m_document.ErrorId() << " : " << m_document.ErrorDesc() << endl;
    }else
        m_lecture = true;
}

void onea::carte::MapLoader::load()
{
    if( m_lecture ){

        loadTexture();

        cout << "Bien ! : " << m_textures.getTaille() << endl;

    }
}

bool onea::carte::MapLoader::verifDocument()
{
    TiXmlHandle hd1(&m_document);
    TiXmlElement *elm = hd1.FirstChildElement().Element();

    if( string(elm->Value()) != "carte" )
        return true;
    else return false;
}

void onea::carte::MapLoader::loadTexture()
{
    TiXmlHandle hd( &m_document );
    TiXmlElement *elm = hd.FirstChildElement().FirstChildElement().Element();

    while( elm ){

        if( string(elm->Value()) == "texture" ){

            string nomFichier( elm->Attribute("fichier") );
            int id(0);

            elm->QueryIntAttribute("id", &id);

            m_textures.addTexture( nomFichier, (unsigned int)id );

            elm = elm->NextSiblingElement();
        }

    }
}

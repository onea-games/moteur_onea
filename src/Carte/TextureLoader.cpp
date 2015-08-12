#include "TextureLoader.hpp"

#include <iostream>

onea::carte::TextureLoader::TextureLoader(TiXmlDocument *document)
    : Loader(document, "texture")
{
}

bool onea::carte::TextureLoader::load()
{
    TiXmlHandle handle(m_document);
    TiXmlElement *elm = handle.FirstChildElement().FirstChildElement().Element();

    std::cout << elm->Value() << std::endl;

    while( elm ){

        if( elm->Value() == m_nomBalise ){
            textureLoad l;
            sf::Texture texture;
            std::string filePath;

            if( elm->QueryStringAttribute("fileName", &filePath) == TIXML_SUCCESS ){

                if( texture.loadFromFile(filePath) ){
                    l.texture = texture;

                    if( elm->QueryIntAttribute("id", &l.id) != TIXML_SUCCESS )
                        l.id = m_cont.size();

                    m_cont.push_back(l);
                }
            }
        }

        elm = elm->NextSiblingElement();
    }

    return true;
}

std::vector<onea::carte::textureLoad> &onea::carte::TextureLoader::getVector()
{
    return m_cont;
}

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
            sf::Texture texture;
            std::string filePath;

            if( elm->QueryStringAttribute("fileName", &filePath) == TIXML_SUCCESS ){
                texture.loadFromFile(filePath);

                m_cont.push_back(texture);
            }
        }

        elm = elm->NextSiblingElement();
    }

    return true;
}

std::vector<sf::Texture> &onea::carte::TextureLoader::getVector()
{
    return m_cont;
}

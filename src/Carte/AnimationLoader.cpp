#include "AnimationLoader.hpp"

onea::carte::AnimationLoader::AnimationLoader(TiXmlDocument *document)
    : Loader(document, "animation")
{
}

bool onea::carte::AnimationLoader::load()
{
    TiXmlHandle handle(m_document);
    TiXmlElement *elm = handle.FirstChildElement().FirstChildElement().Element();

    std::cout << elm->Value() << std::endl;

    while( elm ){

        if( elm->Value() == m_nomBalise ){

            animLoader anim;
            int idTileSet, ligne;

            if( elm->QueryIntAttribute("id", &anim.id) == TIXML_SUCCESS ){

                if( elm->QueryStringAttribute("name", &anim.name) == TIXML_SUCCESS ){

                    if( elm->QueryIntAttribute("idTileSet", &idTileSet) == TIXML_SUCCESS ){

                        if( elm->QueryIntAttribute("ligne", &ligne) == TIXML_SUCCESS ){



                        }

                    }

                }

            }

        }

        elm = elm->NextSiblingElement();
    }

    return true;
}

#ifndef MAPLOADER_HPP
#define MAPLOADER_HPP

#include <SFML/Graphics/Texture.hpp>

#include <tinyxml.h>
#include <iostream>
#include <string>

#include "ListeTexture.hpp"

using namespace sf;
using namespace std;

namespace onea
{
    namespace carte
    {

        class MapLoader
        {
        public:
            MapLoader( string nomFichier );

            void load();

        protected:
            bool verifDocument();

            void loadTexture();

            TiXmlDocument m_document;
            ListeTexture m_textures;

            bool m_lecture;
        };

    }
}

#endif // MAPLOADER_HPP

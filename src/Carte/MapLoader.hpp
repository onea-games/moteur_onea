#ifndef MAPLOADER_HPP
#define MAPLOADER_HPP

#include <SFML/Graphics/Texture.hpp>

#include <tinyxml.h>
#include <iostream>
#include <string>

#include "ListeTexture.hpp"
#include "ListeTileSet.hpp"

namespace onea
{
    namespace carte
    {

        class MapLoader
        {
        public:
            MapLoader( std::string nomFichier );

            void load();

        protected:
            bool verifDocument();

            void loadTexture();
            void loadTileSet();

            TiXmlDocument m_document;

            onea::carte::ListeTexture m_textures;
            onea::carte::ListeTileSet m_tilesets;

            bool m_lecture;
        };

    }
}

#endif // MAPLOADER_HPP

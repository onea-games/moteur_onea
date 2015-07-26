#ifndef TILESETLOADER_HPP
#define TILESETLOADER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

#include <string>

#include "Loader.hpp"
#include "TileSet.hpp"

namespace onea
{
    namespace carte
    {

        class TileSetLoader : public onea::carte::Loader
        {
        public:
            TileSetLoader() = delete;

            TileSetLoader( string nom, unsigned int id, sf::Texture *texture, sf::Vector2f tailleTile );

            onea::carte::TileSet tileset;
        };

    }
}

#endif // TILESETLOADER_HPP

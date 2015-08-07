#ifndef TILELOADER_HPP
#define TILELOADER_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Loader.cpp"
#include "Tile.hpp"
#include "TextureLoader.hpp"

using namespace sf;
using namespace std;

namespace onea
{

    namespace carte
    {

        class TileLoader : public Loader
        {
        public:
            TileLoader() = delete;

            TileLoader( unsigned int id, onea::carte::Tile tile )
                : Loader("", id),
                  tile(tile)
            {
            }

            TileLoader( unsigned int id, Texture *texture, Vector2f positionTexture, Vector2f position = Vector2f(), Vector2f taille = Vector2f() )
                : Loader("", id),
                  tile(texture, positionTexture, position, taille)
            {
            }

            Tile tile;
        };

    }

}

#endif

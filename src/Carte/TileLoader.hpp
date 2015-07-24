#ifndef TILELOADER_HPP
#define TILELOADER_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Loader.hpp"
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

            TileLoader( string nom, unsigned int id, onea::carte::Tile tile )
                : Loader(nom, id),
                  tile(tile)
            {
            }


            friend bool operator<( const TextureLoader &left, const TextureLoader &right )
            {
                return left.id < right.id;
            }

            Tile tile;
        };

    }

}

#endif

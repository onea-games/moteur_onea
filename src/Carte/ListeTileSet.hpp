#ifndef LISTETILESET_HPP
#define LISTETILESET_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Liste.hpp"
#include "TileSetLoader.hpp"

namespace onea
{
    namespace carte
    {

        class ListeTileSet : public onea::carte::Liste<onea::carte::TileSetLoader>
        {
        public:
            ListeTileSet();

            void add(unsigned int id, sf::Texture *texture, sf::Vector2f tailleTile);
            void add(unsigned int id);

            bool del(unsigned int id);

            const onea::carte::TileSet *get(unsigned int id);
        };

    }
}

#endif // LISTETILESET_HPP

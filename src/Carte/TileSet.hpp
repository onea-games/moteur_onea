#ifndef TILESET_HPP
#define TILESET_HPP

#include <SFML/Graphics.hpp>

#include "Tile.hpp"
#include "TileLoader.hpp"

namespace onea
{
    namespace carte
    {

        class TileSet : protected Entite
        {
        public:
            TileSet() = delete;
            TileSet( sf::Texture *texture, sf::Vector2f tailleTile );

            Tile getTile(Vector2f pos);
            Tile getTile(float x, float y);

        protected:
            sf::Vector2f m_tailleTile;
            std::vector<onea::carte::Tile> m_tiles;
            size_t m_nombreLargeur, m_nombreHauteur;
        };

    }
}

#endif // TILESET_HPP

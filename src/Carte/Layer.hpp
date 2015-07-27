#ifndef LAYER_HPP
#define LAYER_HPP

#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>

#include "../Entite.hpp"
#include "Tile.hpp"

namespace onea
{
    namespace carte
    {
        class tilePosition{
        public:
            onea::carte::Tile tile;
            sf::Vector2f positionAbs; // Position Absolue

            tilePosition( const Tile &tile, sf::Vector2f positionAbs )
                : tile(tile),
                  positionAbs(positionAbs)
            {}

        };

        class Layer : public sf::Drawable
        {
        public:
            Layer( sf::Vector2f position = sf::Vector2f(), sf::Vector2f tailleTile = sf::Vector2f() );

            void addTile( sf::Vector2f position, Tile &tile );
            void addTile( float x, float y, Tile &tile );

            bool delTile( sf::Vector2f position );
            bool delTile( float x, float y );

        protected:
            void draw(sf::RenderTarget &target, sf::RenderStates states) const;

            std::vector<tilePosition> m_tiles;
            sf::Vector2f m_tailleTile;
        };
    }
}

#endif // LAYER_HPP

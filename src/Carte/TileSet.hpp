#ifndef TILESET_HPP
#define TILESET_HPP

#include <vector>
#include <string>
#include <iostream>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../Entite.hpp"

namespace onea
{
    namespace carte
    {
        class TileSet : public sf::Drawable
        {
        public:
            TileSet() = delete;
            TileSet(std::string filePath, sf::Vector2u size);
            TileSet(sf::Texture *texture, sf::Vector2u size);

            ~TileSet();

            bool load();

            vector<sf::Sprite> getLine(unsigned int y) const;

            const sf::Sprite &operator [](unsigned i)
            {
                if( i < m_sprite.size() )
                    return m_sprite[i];
                else
                    return m_sprite.back();
            }

        protected:
            void draw(RenderTarget &target, RenderStates states) const;

            sf::Texture *m_texture;
            sf::Vector2u m_size;
            vector<sf::Sprite> m_sprite;

        private:
            bool m_init;
        };
    }
}

#endif // TILESET_HPP

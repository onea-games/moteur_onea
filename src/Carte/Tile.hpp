#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

#include <vector>

#include "../Entite.hpp"

using namespace sf;
using namespace std;

namespace onea
{
    namespace carte
    {

        class Tile : public Entite, public Drawable
        {
        public:
            Tile(Texture *texture, Vector2f positionTexture, Vector2f position, Vector2f taille);

        protected:
            virtual void draw( RenderTarget &target, RenderStates states ) const;

            Texture *m_texture;
            Sprite m_sprite;
            IntRect m_textureRect;
        };

    }
}

#endif // TILE_HPP

#ifndef LISTETEXTURE_HPP
#define LISTETEXTURE_HPP

#include <set>
#include <string>

#include <SFML/Graphics/Texture.hpp>

#include "TextureLoader.hpp"

namespace onea
{

    namespace carte
    {

        class ListeTexture
        {
        public:
            ListeTexture();

            void addTexture( string nom, unsigned int id );

            bool delTexture( unsigned int id );

            const Texture *getTexture( unsigned int id ) const;

            size_t getTaille() const;

        protected:
            set<TextureLoader> m_texture;
        };

    }

}

#endif // LISTETEXTURE_HPP

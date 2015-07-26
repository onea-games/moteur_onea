#ifndef LISTETEXTURE_HPP
#define LISTETEXTURE_HPP

#include <set>
#include <string>

#include <SFML/Graphics/Texture.hpp>

#include "TextureLoader.hpp"
#include "Liste.hpp"

namespace onea
{

    namespace carte
    {

        class ListeTexture : public onea::carte::Liste<onea::carte::TextureLoader>
        {
        public:
            ListeTexture();

            void add( string nom, unsigned int id );
            void add( unsigned int id );

            bool del( unsigned int id );

            const Texture *get( unsigned int id ) const;

        protected:
            set< TextureLoader > m_texture;
        };

    }

}

#endif // LISTETEXTURE_HPP

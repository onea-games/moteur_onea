#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Loader.hpp"

namespace onea
{

    namespace carte
    {

        class TextureLoader : public onea::carte::Loader
        {
        public:
            TextureLoader() = delete;

            TextureLoader( string nom, unsigned int id );

            Texture texture;
        };

    }

}

#endif

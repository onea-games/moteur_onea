#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Loader.hpp"

using namespace sf;
using namespace std;

namespace onea
{

    namespace carte
    {

        class TextureLoader : public Loader
        {
        public:
            TextureLoader() = delete;

            TextureLoader( string nom, unsigned int id )
                : Loader(nom, id)
            {
                texture.loadFromFile( nom );
            }

            Texture texture;
        };

    }

}

#endif

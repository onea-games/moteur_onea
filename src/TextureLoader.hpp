#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

namespace onea
{

    namespace carte
    {

        class TextureLoader
        {
        public:
            TextureLoader() = delete;

            TextureLoader( string nom, unsigned int id );

            const string nom;
            const unsigned int id;
            Texture texture;
        };

    }

}

#endif

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

            friend bool operator<( const TextureLoader &left, const TextureLoader &right )
            {
                return left.id < right.id;
            }

            const string nom;
            const unsigned int id;
            Texture texture;
        };

    }

}

#endif

#ifndef TEXTURELOADER_HPP
#define TEXTURELOADER_HPP

#include <vector>
#include <string>

#include <SFML/Graphics/Texture.hpp>

#include "Loader.hpp"

namespace onea
{
    namespace carte
    {
        class TextureLoader : public onea::carte::Loader<sf::Texture>
        {
        public:
            TextureLoader(TiXmlDocument *document);

            bool load();

            std::vector<sf::Texture> &getVector();
        };
    }
}

#endif // TEXTURELOADER_HPP

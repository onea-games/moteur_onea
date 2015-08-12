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
        typedef struct textureLoad{
            sf::Texture texture;
            int id;
        } texture;

        class TextureLoader : public onea::carte::Loader<textureLoad>
        {
        public:
            TextureLoader(TiXmlDocument *document);

            bool load();

            std::vector<textureLoad> &getVector();
        };
    }
}

#endif // TEXTURELOADER_HPP

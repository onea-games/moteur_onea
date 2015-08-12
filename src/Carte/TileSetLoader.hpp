#ifndef TILESETLOADER_HPP
#define TILESETLOADER_HPP

#include <tinyxml.h>

#include "Loader.hpp"
#include "TileSet.hpp"
#include "TextureLoader.hpp"

namespace onea
{
    namespace carte
    {
        typedef struct tilesetLoader{
            TileSet *tileset;
            int id;
        } tilesetLoader;

        class TileSetLoader : public Loader<tilesetLoader>
        {
        public:
            TileSetLoader(TiXmlDocument *document, TextureLoader *texLoad);

            bool load();

            std::vector<tilesetLoader> &getVector();
        protected:
            TextureLoader *m_texLoad;
        };
    }
}

#endif // TILESETLOADER_HPP

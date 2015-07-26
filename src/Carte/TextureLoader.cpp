#include "TextureLoader.hpp"

onea::carte::TextureLoader::TextureLoader( string nom, unsigned int id )
    : onea::carte::Loader(nom, id),
      texture()
{
    texture.loadFromFile( nom );
}

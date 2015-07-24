#include "TextureLoader.hpp"

onea::carte::TextureLoader::TextureLoader( string nom, unsigned int id )
    : nom(nom),
      id(id),
      texture()
{
    texture.loadFromFile( nom );
}

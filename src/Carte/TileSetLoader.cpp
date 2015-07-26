#include "TileSetLoader.hpp"

onea::carte::TileSetLoader::TileSetLoader(string nom, unsigned int id, sf::Texture *texture, sf::Vector2f tailleTile)
    : onea::carte::Loader(nom, id),
      tileset(texture, tailleTile)
{
}

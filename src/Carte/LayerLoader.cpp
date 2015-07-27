#include "LayerLoader.hpp"

onea::carte::LayerLoader::LayerLoader( unsigned int id, onea::carte::Layer &layer )
    : Loader("", id),
      layer(layer)
{
}

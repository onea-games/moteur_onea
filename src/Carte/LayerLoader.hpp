#ifndef LAYERLOADER_HPP
#define LAYERLOADER_HPP

#include "Loader.cpp"
#include "Layer.hpp"

namespace onea
{
    namespace carte
    {

        class LayerLoader : public onea::carte::Loader
        {
        public:
            LayerLoader() = delete;

            LayerLoader( unsigned int id, onea::carte::Layer &layer );

            onea::carte::Layer layer;
        };

    }
}

#endif // LAYERLOADER_HPP

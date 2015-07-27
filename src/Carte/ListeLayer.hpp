#ifndef LISTELAYER_HPP
#define LISTELAYER_HPP

#include "Liste.hpp"
#include "LayerLoader.hpp"

namespace onea
{
    namespace carte
    {

        class ListeLayer : public onea::carte::Liste<onea::carte::LayerLoader>
        {
        public:
            ListeLayer();

            void add(unsigned int id, onea::carte::Layer &layer);

            bool del(unsigned int id);
        protected:
        };

    }
}

#endif // LISTELAYER_HPP

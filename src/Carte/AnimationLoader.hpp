#ifndef ANIMATIONLOADER_HPP
#define ANIMATIONLOADER_HPP

#include <vector>
#include <string>

#include "../Animation/Animation.hpp"
#include "Loader.hpp"

namespace onea
{
    namespace carte
    {
        typedef struct animLoader{
            onea::anim::Animation *animation;
            int id;
            std::string name;
        }animLoader;

        class AnimationLoader : public onea::carte::Loader
        {
        public:
            AnimationLoader(TiXmlDocument *document);

            bool load();

            std::vector<animLoader> &getVector();
        };
    }
}

#endif // ANIMATIONLOADER_HPP

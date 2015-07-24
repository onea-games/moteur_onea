#ifndef LOADER_HPP
#define LOADER_HPP

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

namespace onea
{

    namespace carte
    {

        class Loader
        {
        public:
            Loader() = delete;

            Loader( string nom, unsigned int id )
                : nom(nom),
                  id(id)
            {
            }


            friend bool operator<( const Loader &left, const Loader &right )
            {
                return left.id < right.id;
            }

            const string nom;
            const unsigned int id;
        };

    }

}

#endif

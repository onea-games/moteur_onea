#ifndef LISTE_HPP
#define LISTE_HPP

#include <set>
#include <cstddef>

#include "Loader.cpp"

namespace onea
{
    namespace carte
    {
        template <typename T>
        class Liste
        {
        public:
            Liste()
                : m_type()
            {
            }

            virtual void add(unsigned int id) = 0;

            virtual bool del(unsigned int id) = 0;

            size_t getTaille() const
            {
                return m_type.size();
            }

        protected:
            std::set<T> m_type;
        };

    }
}


#endif // LISTE_HPP

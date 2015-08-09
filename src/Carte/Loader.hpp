#ifndef LOADER_CPP
#define LOADER_CPP

#include <tinyxml.h>

#include <vector>
#include <string>

namespace onea
{
    namespace carte
    {
        template <typename T>
        class Loader
        {
        public:
            Loader() = delete;
            Loader(TiXmlDocument *document, std::string nomBalise)
                : m_nomBalise(nomBalise),
                  m_cont(),
                  m_document(document)
            {
            }

            virtual bool load() = 0;

            virtual std::vector<T>  &getVector() = 0;

        protected:
            std::string m_nomBalise;
            std::vector<T> m_cont;
            TiXmlDocument *m_document;
        };
    }
}

#endif // LOADER_CPP

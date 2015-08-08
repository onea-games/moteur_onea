#ifndef STACK_HPP
#define STACK_HPP

#include <vector>

namespace onea
{
    template <typename T>
    class Stack
    {
    public:
        Stack(unsigned int maxSize)
            : m_size(0),
              m_sizeMax(maxSize),
              m_stack()

        {
        }

        void push( const T &elm )
        {
            if( m_size + 1 < m_sizeMax ){
                m_stack.push_back(elm);
                ++m_size;
            } else{
                m_stack.erase( m_stack.begin() );
                m_stack.push_back(elm);
            }
        }

        const T &head()
        {
            return m_stack.end();
        }

        const T &pop()
        {
            T elm = m_stack.back();
            m_stack.pop_back();
            --m_size;

            return elm;
        }

        const T &get( unsigned int i ) const
        {
            if( i >= m_size )
                i = m_size - 1;

            return m_stack[i-m_size];
        }

        int size() const
        {
            return m_size;
        }

    protected:
        unsigned int    m_size,
                        m_sizeMax;
        std::vector<T> m_stack;
    };
}

#endif // STACK_HPP

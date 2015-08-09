#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <vector>

#include "LigneShape.hpp"

using namespace sf;
using namespace std;

namespace onea
{

    template<typename T>
    class Shape
    {
    public:
        Shape( Vector2<T> position )
            : m_position(position),
              m_shape()
        {}

        /** Renvoie true si le point (x, y) est dans la shape. */
        bool contains(T x, T y);

        /** Renvoie true si le point est dans la shape. */
        bool contains(Vector2<T> point);

        /** Renvoie true si shape est dans cette shape. */
        bool intersect(Shape<T> shape);

        /** Renvoie toutes les LigneShape du shape. */
        const vector< LigneShape<T> > &getLigneShape() const
        {
            return m_shape;
        }

        const Vector2<T> getPosition() const
        {
            return m_position;
        }

        void move(float x, float y)
        {
            m_position.x = x;
            m_position.y = y;
        }

        bool operator==( const Shape<T> &right ) const
        {
            return right.m_position == m_position;
        }

    public:
        Vector2<T> m_position;
        vector< LigneShape<T> > m_shape;
    };

}

#endif // SHAPE_HPP

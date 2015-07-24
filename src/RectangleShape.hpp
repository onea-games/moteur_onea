#ifndef RECTANGLE_SHAPE
#define RECTANGLE_SHAPE

#include "Shape.hpp"

using namespace sf;
using namespace std;

namespace onea
{

    template<typename T>
    class RectangleShape : public Shape<T>
    {

    public:
        RectangleShape(Vector2<T> position = Vector2<T>(), Vector2<T> taille = Vector2f())
            : Shape<T>::Shape(position),
              m_taille(taille)
        {
            this->m_shape.push_back( LigneShape<T>( Vector2<T>( this->m_position.x, this->m_position.y ), Vector2<T>( this->m_position.x + m_taille.x, this->m_position.y ) ) );
            this->m_shape.push_back( LigneShape<T>( Vector2<T>( this->m_position.x + m_taille.x, this->m_position.y ), Vector2<T>( this->m_position + m_taille ) ) );
            this->m_shape.push_back( LigneShape<T>( Vector2<T>(this->m_position + m_taille), Vector2<T>( this->m_position.x, this->m_position.y + m_taille.y ) ) );
            this->m_shape.push_back( LigneShape<T>( Vector2<T>(this->m_position.x, this->m_position.y + m_taille.y), Vector2f( this->m_position ) ) );
        }

        bool contains(T x, T  y)
        {
            return x > this->m_position.x && x < this->m_position.x + this->m_taille.x
                && y > this->m_position.y && y < this->m_position.y + this->m_taille.y;
        }

        bool contains(Vector2<T> point)
        {
            return contains(point.x, point.y);
        }

        bool intersect(RectangleShape<T> &shape) const
        {
            return  contains( shape.m_position ); // A FINIR CAR J'AI LA FLEMME
        }

        bool operator==( const RectangleShape &shape ) const
        {
            if( this->m_position == shape->m_position && m_taille == shape.m_taille )
                return true;
            return false;
        }

    protected:
        Vector2<T> m_taille;
    };

    typedef RectangleShape<int> IntRectangleShape;
    typedef RectangleShape<float> FloatRectangleShape;

}

#endif // RECTANGLE_SHAPE

/*
 * LigneShape.h
 *
 *  Created on: 7 juil. 2015
 *      Author: alexis
 */

#ifndef LIGNESHAPE_H_
#define LIGNESHAPE_H_

#include <SFML/Graphics.hpp>

using namespace sf;

namespace onea
{

    template <typename T>
    class LigneShape : public Drawable
    {
    public:
        LigneShape(Vector2<T> pt1, Vector2<T> pt2, Color couleur = Color::Red)
        	: pt1(),
              pt2()
        {
            this->pt1.position = pt1;
            this->pt1.color = couleur;

            this->pt2.position = pt2;
            this->pt2.color = couleur;
        }

        Vertex pt1;
        Vertex pt2;

    protected:
        virtual void draw( RenderTarget &target, RenderStates states ) const
        {
            VertexArray arr;
            arr.resize(2);
            arr.setPrimitiveType(Lines);

            arr[0] = pt1;
            arr[1] = pt2;

            target.draw(arr, states);
        }

    };

}

#endif /* LIGNESHAPE_H_ */

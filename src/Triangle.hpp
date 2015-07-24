/*
 * triangle.h
 *
 *  Created on: 6 juil. 2015
 *      Author: alexis
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <SFML/Graphics.hpp>

using namespace sf;

class Triangle : public Drawable
{
public:
	Triangle();

	void AddPoint(float x, float y, Color couleur1, Color couleur2);

	void setPosition(Vector2f position);
protected:
	virtual void draw (RenderTarget &target, RenderStates states) const;

	VertexArray m_triangle;
	unsigned int m_count;
};

#endif /* TRIANGLE_H_ */

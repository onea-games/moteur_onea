/*
 * triangle.cpp
 *
 *  Created on: 6 juil. 2015
 *      Author: alexis
 */

#include "Triangle.hpp"

Triangle::Triangle()
	: m_triangle(Triangles, 3),
	  m_count()
{
	m_triangle.setPrimitiveType(Triangles);
}

void Triangle::AddPoint(float x, float y, Color couleur1, Color couleur2)
{
	if( m_count < 3 ){
		m_triangle[m_count].position = Vector2f(x, y);
		m_triangle[m_count].color = couleur1;
		m_count++;
	}
}

void Triangle::setPosition(Vector2f position)
{
	for( unsigned int i; i < m_count; i++ ){
		m_triangle[i].position.x += position.x;
		m_triangle[i].position.y += position.y;
	}
}

void Triangle::draw( RenderTarget &target, RenderStates states ) const
{
	target.draw(m_triangle, RenderStates(states));
}

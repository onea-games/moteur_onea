/*
 * Lumiere.cpp
 *
 *  Created on: 6 juil. 2015
 *      Author: alexis
 */

#include "Lumiere.hpp"

onea::Lumiere::Lumiere()
	: m_position(),
	  m_rayon(),
	  m_couleur(),
	  m_intensite(),
	  m_qualite()
{
}

onea::Lumiere::Lumiere(Vector2f position, float intensite, float rayon, unsigned int qualite, Color couleur)
	: m_position(position),
	  m_rayon(rayon),
	  m_couleur(couleur),
	  m_intensite(intensite),
	  m_qualite(qualite)
{
}

void onea::Lumiere::setPosition(Vector2f position)
{
	m_position = position;
}

const Vector2f &onea::Lumiere::getPosition() const
{
	return m_position;
}

void onea::Lumiere::setRayon(float rayon, vector< LigneShape<float> > &rect)
{
	m_rayon = rayon;

	Generate(rect);
}

float onea::Lumiere::getRayon() const
{
	return m_rayon;
}

void onea::Lumiere::AddTriangle(Vector2f pt1, Vector2f pt2, int minimum_wall, vector< LigneShape<float> > &m_wall)
{
	int w = minimum_wall;
	for(std::vector< LigneShape<float> >::iterator IterWall=m_wall.begin()+minimum_wall;IterWall!=m_wall.end();++IterWall,++w)
	{
		// l1 et l2 sont les positions relatives au centre de la lumière des deux extrémités du mur
		sf::Vector2f l1(IterWall->pt1.position.x-m_position.x, IterWall->pt1.position.y-m_position.y);
		sf::Vector2f l2(IterWall->pt2.position.x-m_position.x, IterWall->pt2.position.y -m_position.y);

		if(l1.x * l1.x + l1.y * l1.y < m_rayon * m_rayon){
			Vector2f i = Intersect(pt1,pt2,sf::Vector2f (0,0),l1);

			if (pt1 != i && pt2 != i)
				if((pt1.x >= i.x && pt2.x <= i.x) || (pt1.x <= i.x && pt2.x >= i.x))
					if((pt1.y >= i.y && pt2.y <= i.y) || (pt1.y <= i.y && pt2.y >= i.y))
						if((l1.y >= 0 && i.y >= 0) || (l1.y <= 0 && i.y <= 0))
							if((l1.x >= 0 && i.x >= 0) || (l1.x <= 0 && i.x <= 0))
								AddTriangle(i, pt2, w, m_wall), pt2 = i;
		}

		if(l2.x * l2.x + l2.y * l2.y < m_rayon * m_rayon){
			sf::Vector2f i = Intersect(pt1,pt2,sf::Vector2f (0,0),l2);
			if (pt1 != i && pt2 != i)
				if((pt1.x >= i.x && pt2.x <= i.x) || (pt1.x <= i.x && pt2.x >= i.x))
					if((pt1.y >= i.y && pt2.y <= i.y) || (pt1.y <= i.y && pt2.y >= i.y))
						if((l2.y >= 0 && i.y >= 0) || (l2.y <= 0 && i.y <= 0))
							if((l2.x >= 0 && i.x >= 0) || (l2.x <= 0 && i.x <= 0))
								AddTriangle(pt1, i, w, m_wall), pt1 = i;
		}

		sf::Vector2f m = Collision(l1, l2, sf::Vector2f(0,0), pt1);
		sf::Vector2f n = Collision(l1, l2, sf::Vector2f(0,0), pt2);
		sf::Vector2f o = Collision(l1, l2, pt1, pt2);

		if((m.x != 0 || m.y != 0) && (n.x != 0 || n.y != 0))
			pt1 = m, pt2 = n;
		else
		{
			if((m.x != 0 || m.y != 0) && (o.x != 0 || o.y != 0))
				AddTriangle(m ,o , w, m_wall), pt1 = o;
			if((n.x != 0 || n.y != 0) && (o.x != 0 || o.y != 0))
				AddTriangle(o ,n , w, m_wall), pt2 = o;
		}

	}

    float intensity;

    m_shape.push_back(Triangle());

    m_shape.back().AddPoint(0, 0,  sf::Color((int)(m_intensite*m_couleur.r/255),
                                             (int)(m_intensite*m_couleur.g/255),
                                             (int)(m_intensite*m_couleur.b/255)),sf::Color(255,255,255)
);

    intensity = m_intensite-sqrt(pt1.x*pt1.x + pt1.y*pt1.y)*m_intensite/m_rayon;
    m_shape.back().AddPoint(pt1.x, pt1.y,  sf::Color((int)(intensity*m_couleur.r/255),
                                                     (int)(intensity*m_couleur.g/255),
                                                     (int)(intensity*m_couleur.b/255)),sf::Color(255,255,255));

    intensity = m_intensite-sqrt(pt2.x*pt2.x + pt2.y*pt2.y)*m_intensite/m_rayon;
    m_shape.back().AddPoint(pt2.x, pt2.y,  sf::Color((int)(intensity*m_couleur.r/255),
                                                     (int)(intensity*m_couleur.g/255),
                                                     (int)(intensity*m_couleur.b/255)),sf::Color(255,255,255));

    m_shape.back().setPosition(m_position);
}


void onea::Lumiere::Generate(vector< LigneShape<float> > &vec)
{
    m_shape.clear();

    float buf=(M_PI*2)/(float)m_qualite;

    for(unsigned int i=0;i < m_qualite;++i)
    {
        AddTriangle(sf::Vector2f((float)((float)m_rayon*cos((float)i*buf))
                                ,(float)((float)m_rayon*sin((float)i*buf))) ,
                    sf::Vector2f((float)((float)m_rayon*cos((float)(i+1)*buf))
                                ,(float)((float)m_rayon*sin((float)(i+1)*buf))), 0, vec);
    }
}

Vector2f onea::Lumiere::Intersect(Vector2f p1, Vector2f p2, Vector2f q1, Vector2f q2)
{
	sf::Vector2f i;
	if((p2.x - p1.x) == 0 && (q2.x - q1.x) == 0)
		i.x = 0, i.y = 0;
	else if((p2.x - p1.x) == 0){
		i.x = p1.x;
		float c = (q2.y - q1.y) / (q2.x - q1.x);
		float d = q1.y - q1.x * c;
		i.y = c * i.x + d;
	} else if((q2.x - q1.x) == 0){
		i.x = q1.x;
		float a = (p2.y - p1.y) / (p2.x - p1.x);
		float b = p1.y - p1.x * a;
		i.y = a * i.x + b;
	} else{
		float a = (p2.y - p1.y) / (p2.x - p1.x);
		float b = p1.y - p1.x * a;
		float c = (q2.y - q1.y) / (q2.x - q1.x);
		float d = q1.y - q1.x * c;
		i.x = (d-b)/(a-c);
		i.y = a * i.x + b;
	}

	return i;
}

Vector2f onea::Lumiere::Collision(Vector2f p1, Vector2f p2, Vector2f q1, Vector2f q2)
{
	Vector2f i;
	i = Intersect(p1, p2, q1, q2);

	if( ((i.x >= p1.x - 0.1 && i.x <= p2.x + 0.1)
			|| (i.x >= p2.x - 0.1 && i.x <= p1.x + 0.1))
			&& ((i.x >= q1.x - 0.1 && i.x <= q2.x + 0.1)
			|| (i.x >= q2.x - 0.1 && i.x <= q1.x + 0.1))
			&& ((i.y >= p1.y - 0.1 && i.y <= p2.y + 0.1 )
			|| (i.y >= p2.y - 0.1 && i.y <= p1.y + 0.1))
			&& ((i.y >= q1.y - 0.1 && i.y <= q2.y + 0.1)
			|| (i.y >= q2.y - 0.1 && i.y <= q1.y + 0.1))
		)
				return i;
	else
		return Vector2f(0, 0);
}

void onea::Lumiere::draw(RenderTarget &target, RenderStates states) const
{
	for( size_t i = 0; i < m_shape.size(); i++ )
		target.draw(m_shape[i], BlendAdd);
}

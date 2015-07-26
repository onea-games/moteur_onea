/*
 * Lumiere.h
 *
 *  Created on: 6 juil. 2015
 *      Author: alexis
 */

#ifndef LUMIERE_H_
#define LUMIERE_H_

#include <SFML/Graphics.hpp>
#include <vector>

#include <iostream>

#include "../Triangle.hpp"
#include "../LigneShape.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

using namespace sf;
using namespace std;

namespace onea
{

    class Lumiere : public Drawable
    {
    public:
        Lumiere();
        Lumiere(Vector2f position, float intensite, float rayon, unsigned int qualite, Color couleur);

        void setPosition(Vector2f position);
        const Vector2f &getPosition() const;

        void setRayon(float rayon, vector< LigneShape<float> > &vec);
        float getRayon() const;

        void AddTriangle(Vector2f pt1, Vector2f pt2, int minimum_wall, vector< LigneShape<float> > &m_wall);

        void Generate(vector< LigneShape<float> > &vec);

        Vector2f Intersect(Vector2f p1, Vector2f p2, Vector2f q1, Vector2f q2);

        Vector2f Collision(Vector2f p1, Vector2f p2, Vector2f q1, Vector2f q2);
    protected:
        virtual void draw(RenderTarget& target, RenderStates states) const;

        Vector2f m_position;
        float m_rayon;
        Color m_couleur;
        float m_intensite;
        unsigned int m_qualite;

        vector<Triangle> m_shape;
    };

}

#endif /* LUMIERE_H_ */

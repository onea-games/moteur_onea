#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#define DEF_TIME_ANIM 0.3

namespace onea
{
  namespace anim
  {
    class Animation : public sf::Drawable
    {
    public:
      Animation( sf::Texture *, float = DEF_TIME_ANIM);

      /**
       * /brief Met a jour l'animation.
       */
      void update();

      /**
       * /brief Ajoute une animation en fin de tableau.
       * /return void
       */
      void addAnim( sf::IntRect );

      /**
        * /brief Modifier le temps de l'animation.
        */
      void setTempsAnimation(float tempsAnimation);

      /**
        * /brief Retourne le temps de l'animation.
        * /return Le temps de l'animation.
        */
      float getTempsAnimation() const;

    protected:
      void draw(sf::RenderTarget &target, sf::RenderStates states) const;

      sf::Texture *m_texture;
      float m_tempsAnim; // Est le temps que dure toute l'animation.
      float m_tempsParAnim; // Le temps par animation
      sf::Clock m_clock;
      sf::Sprite m_sprite;

      std::vector<sf::IntRect> m_animRect;
      unsigned int m_count;
    };
  }
}

#endif // ANIMATION_HPP

#include "Animation.hpp"

onea::anim::Animation::Animation(sf::Texture *texture, float tempsAnimation)
    : Drawable(),
      m_texture(texture),
      m_tempsAnim(tempsAnimation),
      m_tempsParAnim(0),
      m_clock(),
      m_sprite(),
      m_animRect()
{
    m_sprite.setTexture(*m_texture);
}

void onea::anim::Animation::update()
{
    if( m_clock.getElapsedTime().asSeconds() >= m_tempsParAnim ){
        if( ++m_count > m_animRect.size() )
            m_count = 0;

        m_sprite.setTextureRect( m_animRect[m_count] );

        m_clock.restart();
    }
}

void onea::anim::Animation::addAnim(sf::IntRect rect)
{
    m_animRect.push_back(rect);

    if( m_animRect.size() == 0 )
        m_tempsParAnim = 0;
    else
        m_tempsParAnim = m_tempsAnim / m_animRect.size();
}

void onea::anim::Animation::setTempsAnimation(float tempsAnimation)
{
    m_tempsAnim = tempsAnimation;

    if( m_animRect.size() == 0 )
        m_tempsParAnim = 0;
    else
        m_tempsParAnim = m_tempsAnim / m_animRect.size();
}

float onea::anim::Animation::getTempsAnimation() const
{
    return m_tempsAnim;
}

void onea::anim::Animation::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}

#include "Tile.hpp"

onea::carte::Tile::Tile(Texture *texture, Vector2f positionTexture, Vector2f position, Vector2f taille)
    : Entite(position, taille),
      m_texture(texture),
      m_sprite(*texture),
      m_textureRect((Vector2<int>)m_position, (Vector2<int>)m_taille)
{
}

void onea::carte::Tile::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(m_sprite, states);
}

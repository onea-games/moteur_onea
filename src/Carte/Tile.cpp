#include "Tile.hpp"

onea::carte::Tile::Tile(Texture *texture, Vector2f positionTexture, Vector2f position, Vector2f taille)
    : Entite(position, taille),
      m_texture(texture),
      m_sprite(*texture),
      m_textureRect((Vector2<int>)positionTexture, (Vector2<int>)m_taille)
{
    m_sprite.setTextureRect(m_textureRect);
}

onea::carte::Tile::Tile( const onea::carte::Tile &tile )
    : onea::Entite::Entite(tile),
      m_texture(tile.m_texture),
      m_sprite(tile.m_sprite),
      m_textureRect(tile.m_textureRect)
{
}

void onea::carte::Tile::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(m_sprite, states);
}

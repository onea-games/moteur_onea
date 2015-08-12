#include "TileSet.hpp"

onea::carte::TileSet::TileSet(string filePath, Vector2u size)
    : m_size(size),
      m_sprite(),
      m_init(false)
{
    m_texture = new Texture();

    m_texture->loadFromFile(filePath);
}

onea::carte::TileSet::TileSet(Texture *texture, Vector2u size)
    : m_texture(texture),
      m_size(size),
      m_sprite(),
      m_init(true)
{
}

onea::carte::TileSet::~TileSet()
{
    if( !m_init ) // Si non initialisé par un pointeur.
        delete m_texture;
}

bool onea::carte::TileSet::load()
{
    if( m_texture == 0 ){
        std::cerr << "Texture manquante !" << std::endl;
        return false;
    }

    if(     m_texture->getSize().x % m_size.x != 0
        ||  m_texture->getSize().y % m_size.y != 0 ){
        std::cerr << "La taille des tileset n'est pas correcte." << std::endl;
        return false;
    }

    unsigned int partX = m_texture->getSize().x / m_size.x;
    unsigned int partY = m_texture->getSize().y / m_size.y;

    for( unsigned int i = 0; i < partX; ++i ){

        for( unsigned int j = 0; j < partY; ++j ){

            sf::Sprite sprite(*m_texture);
            sprite.setTextureRect(
                            sf::IntRect(i*m_size.x, j*m_size.y, m_size.x, m_size.y)
                        );
            sprite.setPosition(Vector2f(i*m_size.x, j*m_size.y));

            m_sprite.push_back( sprite );

        }

    }

    return true;
}

vector<sf::Sprite> onea::carte::TileSet::getLine(unsigned int y) const
{
    unsigned int partX = m_texture->getSize().x / m_size.x;
    unsigned int dep = y * partX;
    vector<sf::Sprite> sprite;

    for(unsigned int i = 0; i < partX; ++i)
        sprite.push_back( m_sprite[i+dep] );

    return sprite;
}

void onea::carte::TileSet::draw(RenderTarget &target, RenderStates states) const
{
   for( unsigned int i = 0; i < m_sprite.size(); ++i )
        target.draw(m_sprite[i], states);
}

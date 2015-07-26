#include <SFML/Graphics.hpp>

#include <iostream>

#include "src/Entite.hpp"
#include "src/LigneShape.hpp"
#include "src/Physique/Lumiere.hpp"
#include "src/Physique/LumiereDirectionelle.hpp"
#include "src/Physique/CylindreEau.hpp"
#include "src/Carte/MapLoader.hpp"
#include "src/Carte/Tile.hpp"

#include "src/Carte/TileLoader.hpp"

#define VITESSE 5

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    sf::Texture texture;

    onea::Entite ent(Vector2f(0, 0), Vector2f(100, 100));

    texture.loadFromFile("cb.bmp");

    onea::Lumiere lum(Vector2f(100, 100), 125, 100, 50, sf::Color::Yellow);

    vector< onea::LigneShape<float> > vec( ent.getLigneShape() );

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
            else if( event.type == sf::Event::KeyPressed ){

                if( event.key.code == sf::Keyboard::Return )
                    app.close();

            } else if( event.type == sf::Event::MouseMoved ){
                lum.setPosition(Vector2f(event.mouseMove.x, event.mouseMove.y));
            }

        }

        lum.Generate(vec);

        // Clear screen
        app.clear();

        app.draw(lum, sf::BlendAdd);

        for( size_t i = 0; i < vec.size(); ++i )
            app.draw(vec[i]);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

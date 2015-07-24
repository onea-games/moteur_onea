#include <SFML/Graphics.hpp>

#include <iostream>

#include "src/Entite.hpp"
#include "src/LigneShape.hpp"
#include "src/Lumiere.hpp"
#include "src/LumiereDirectionelle.hpp"
#include "src/CylindreEau.hpp"
#include "src/Carte/MapLoader.hpp"
#include "src/Carte/Tile.hpp"

#define VITESSE 5

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    onea::carte::MapLoader map( "test.xml" );

    map.load();

    sf::Texture texture;

    texture.loadFromFile("cb.bmp");

    onea::carte::Tile tile( &texture, (sf::Vector2f)texture.getSize(), sf::Vector2f(0, 0), (sf::Vector2f)texture.getSize() );

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

            }

        }

        // Clear screen
        app.clear();

        app.draw(tile);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

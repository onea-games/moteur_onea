#include <SFML/Graphics.hpp>

#include <iostream>

#include "src/Entite.hpp"
#include "src/LigneShape.hpp"
#include "src/Lumiere.hpp"
#include "src/LumiereDirectionelle.hpp"
#include "src/CylindreEau.hpp"
#include "src/Carte/MapLoader.hpp"

#define VITESSE 5

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    onea::carte::MapLoader map( "test.xml" );

    map.load();

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
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

#include <SFML/Graphics.hpp>

#include <iostream>

#include "src/Physique/CylindreEau.hpp"

#define VITESSE 5

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    onea::physique::CylindreEau cyl(sf::Vector2f(100, 0), 600);

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

        app.draw(cyl);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

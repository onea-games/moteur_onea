#include <SFML/Graphics.hpp>

#include <iostream>

#include "src/Entite.hpp"
#include "src/LigneShape.hpp"
#include "src/Physique/Lumiere.hpp"
#include "src/Physique/LumiereDirectionelle.hpp"
#include "src/Physique/CylindreEau.hpp"
#include "src/Carte/MapLoader.hpp"
#include "src/Carte/Tile.hpp"
#include "src/Carte/Layer.hpp"
#include "src/Carte/TileLoader.hpp"

#define VITESSE 5

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    sf::Texture texture;
    texture.loadFromFile("cb.bmp");

    onea::carte::Tile tile(&texture, sf::Vector2f(), sf::Vector2f(), sf::Vector2f(64, 64));

    onea::carte::Layer layer(sf::Vector2f(), sf::Vector2f(64, 64));

    layer.addTile(0, 0, tile);

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

        app.draw(layer);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

#include <SFML/Graphics.hpp>

#include <iostream>
#include <SFML/Graphics/Texture.hpp>

#include "src/Evenement/Evenement.hpp"
#include "src/Carte/Loader.hpp"

#define VITESSE 5

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    onea::evenement::Input in(&app);

	// Start the game loop
    while (app.isOpen())
    {
        in.updateEvenements();

        if( in.touche(sf::Keyboard::Space) || in.terminer() )
            app.close();

        // Clear screen
        app.clear();

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

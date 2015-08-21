#include <SFML/Graphics.hpp>

#include <tinyxml.h>

#include <iostream>
#include <SFML/Graphics/Texture.hpp>

#include "src/Evenement/Evenement.hpp"
#include "src/Carte/TextureLoader.hpp"
#include "src/Entite.hpp"
#include "src/Carte/TileSet.hpp"
#include "src/Carte/TileSetLoader.hpp"

#define VITESSE 1

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    onea::evenement::Input in(&app);

    while (app.isOpen())
    {
        in.updateEvenements();

        if( in.terminer() )
            app.close();
        else if( in.touche((sf::Keyboard::Space)) )
            app.close();

        // Clear screen
        app.clear();

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

#include <SFML/Graphics.hpp>

#include <tinyxml.h>

#include <iostream>
#include <SFML/Graphics/Texture.hpp>

#include "src/Evenement/Evenement.hpp"
#include "src/Carte/TextureLoader.hpp"
#include "src/Entite.hpp"

#define VITESSE 1

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    onea::evenement::Input in(&app);

    onea::Entite entite(Vector2f(1, 0), Vector2f(64, 64));
    onea::Entite entite_(Vector2f(), Vector2f(64, 64));

    app.setFramerateLimit(64);

	// Start the game loop
    while (app.isOpen())
    {
        in.updateEvenements();

        sf::Vector2f pos(entite.position());

        if( in.touche(sf::Keyboard::Space) || in.terminer() )
            app.close();
        if( in.touche(sf::Keyboard::Down) )
            pos.y += VITESSE;
        if( in.touche(sf::Keyboard::Up) )
            pos.y -= VITESSE;

        entite.bouger(pos);

        cout << entite.position().x << "  " << entite.position().y << endl;

        cout << entite.collision(entite_) << endl;

        // Clear screen
        app.clear();

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

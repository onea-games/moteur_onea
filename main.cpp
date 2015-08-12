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

    TiXmlDocument doc("data/test.xml");

    if( !doc.LoadFile() ){
        std::cerr << "Impossible de lire le fichier" << std::endl;
        return 1;
    }

    onea::carte::TextureLoader tex(&doc);

    tex.load();

    std::cout << tex.getVector().size() << std::endl;

    onea::carte::TileSetLoader tileset(&doc, &tex);

    tileset.load();

    std::cout << tileset.getVector().size() << std::endl;

    sf::Sprite sprite( tex.getVector()[1].texture );
    sprite.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(16, 16)));

	// Start the game loop
    while (app.isOpen())
    {
        in.updateEvenements();

        if( in.terminer() )
            app.close();
        else if( in.touche((sf::Keyboard::Space)) )
            app.close();

        // Clear screen
        app.clear();

        app.draw( *tileset.getVector()[0].tileset );

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

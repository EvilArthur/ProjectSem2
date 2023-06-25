#include <iostream>
#include "Player.h"
#include "SFML/Graphics.hpp"
#include <conio.h>
#include <ctime>

int main(){
    sf::RenderWindow window(sf::VideoMode(720, 960), "SFML works!");
    sf::Texture space;
    space.loadFromFile("texture/fon.png");
    sf::Sprite road(space);
    bool game = true;
    std::vector<std::unique_ptr<GameObject>> gameObjects;

	Spaceship ship("spaceship.png", 254, 682, 206, 243);
    

	sf::Clock clock;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    
            float time = clock.getElapsedTime().asMicroseconds(); // Штука для правлного движения
            clock.restart();
            time = time / 800;

            ship.update(time, gameObjects);
            

        window.clear();
        window.draw(road);
        ship.draw(window);
        for (const auto& gameObject : gameObjects) {
            gameObject->update(time, gameObjects);
        }
        for (const auto& gameObject : gameObjects) {
            gameObject->draw(window);
        }

        window.display();
    }

    return 0;
};
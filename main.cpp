#include <iostream>
#include "Spaceship.h"
#include "gameObject.h"
#include "barrier.h"
#include "SFML/Graphics.hpp"
#include <ctime>

int main(){
    sf::RenderWindow window(sf::VideoMode(720, 960), "SFML works!");
    sf::Texture space;
    space.loadFromFile("texture/fon.png");
    sf::Sprite road(space);
    bool game = true;
    std::vector<std::unique_ptr<GameObject>> gameObjects;
    gameObjects.push_back(std::make_unique<Barrier>("rock.png", 73, -165, 140, 165,"rock"));
    gameObjects.push_back(std::make_unique<Barrier>("base.png", 100, -165*5, 240, 240, "base"));
	Spaceship ship("spaceship.png", 254, 682, 206, 243);
    

	sf::Clock clock;
    int se = rand() % 4;
    std::cout << se << std::endl;

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

           
           
        window.clear();
        window.draw(road);
        ship.draw(window);
        ship.update(time, gameObjects);
        std::cout << gameObjects.size() << std::endl;
        for (const auto& gameObject : gameObjects) {
            if (gameObject != nullptr) {
                gameObject->update(time, gameObjects);
            }
        }
        for (const auto& gameObject : gameObjects) {
            gameObject->draw(window);
        }

        window.display();
    }

    return 0;
};
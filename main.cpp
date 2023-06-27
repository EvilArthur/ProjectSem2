#include <iostream>
#include "Spaceship.h"
#include "gameObject.h"
#include "barrier.h"
#include "SFML/Graphics.hpp"
#include "Logger.h"
#include <ctime>


int main(){

	sf::RenderWindow window(sf::VideoMode(720, 960), "SFML works!");
    sf::Texture space;
    space.loadFromFile("texture/fon.png");
    sf::Sprite road(space);
    bool game = true;
    std::vector<std::unique_ptr<GameObject>> gameObjects;
    gameObjects.push_back(std::make_unique<Barrier>("rock.png", 73, -165, 122, 122,"rock"));
    gameObjects.push_back(std::make_unique<Barrier>("base.png", 100, -165*5, 170, 170, "base"));
	Spaceship ship("spaceship.png", 254, 682, 201, 204);

	sf::Texture over;
    over.loadFromFile("texture/end.png");
    sf::Sprite end(over);
    end.setPosition(0, 0);
   

    

	sf::Clock clock;
    int se = rand() % 4;
    std::cout << se << std::endl;
    logger::Logger::info("Game start");
    while (window.isOpen())
    {
		try {
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			float time = clock.getElapsedTime().asMicroseconds(); 
			clock.restart();
			time = time / 800;


			if (ship.isGameOver() == false) {
				window.clear();
				window.draw(road);
				ship.draw(window);
				//window.draw(end);

				ship.update(time, gameObjects);
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
			else if (ship.isGameOver() == true)
			{
				//window.clear();
				ship.blow(window);
				window.draw(end);
				window.display();
				sf::sleep(sf::seconds(0.9f));
				break;

			}
		}
		catch (const std::exception& e) {
			std::cerr << "Exception occurred: " << e.what() << std::endl;
		}
        
    }

    return 0;
};
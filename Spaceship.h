//
// Created by Admin on 25.06.2023.
//
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "gameObject.h"


class Spaceship: public GameObject {
private:
	int m_x, m_y, m_w, m_h;
	std::string File;
	sf::Texture texture;
	sf::Sprite sprite;
	bool GameOver = false;
	


public:
	
	Spaceship(std::string f, int x, int y, int w, int h);

	void update(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects) override;

	void draw(sf::RenderWindow& window) override;

	void shoot(std::vector<std::unique_ptr<GameObject>>& gameObjects);

	bool isGameOver();

	void blow(sf::RenderWindow& window);

	~Spaceship() override;
	
};

class Shoot: public GameObject
{
private:
	int m_x, m_y, m_w, m_h;
	std::string File;
	sf::Texture texture;
	sf::Sprite sprite;
	bool isDestroyed = true;

public:
	Shoot(std::string f, int x, int y, int w, int h);

	void update(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects) override;

	void draw(sf::RenderWindow& window) override;

	sf::Sprite get_Sprite(); 

	~Shoot() override;
};


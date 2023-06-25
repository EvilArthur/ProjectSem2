//
// Created by Admin on 25.06.2023.
//
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class GameObject
{
private:
	int m_x, m_y, m_w, m_h;
	std::string File;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	GameObject() = default;
	virtual void update(float time) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual ~GameObject() = default;
};

class Spaceship: public GameObject {
private:
	int m_x, m_y, m_w, m_h;
	std::string File;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	
	Spaceship(std::string f, int x, int y, int w, int h);

	void update(float time) override;

	static void shoot( float time);

	void draw(sf::RenderWindow& window) override;

	void shoot(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects);

	~Spaceship() override;
	
};

class Shoot: public GameObject
{
private:
	int m_x, m_y, m_w, m_h;
	std::string File;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Shoot(std::string f, int x, int y, int w, int h);

	void update(float time) override;

	void draw(sf::RenderWindow& window) override;

	~Shoot() override;
};


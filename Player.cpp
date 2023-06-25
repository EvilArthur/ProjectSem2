//
// Created by Admin on 25.06.2023.

#include "Player.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
#include <conio.h>

void GameObject::update(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects)
{
	
}
void GameObject::draw(sf::RenderWindow& window)
{
	
}



Spaceship::Spaceship(std::string f, int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	File = f;
	texture.loadFromFile("texture/" + File);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	sprite.setPosition(x, y);
}

void Spaceship::update(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects)  {

	
	sf::Vector2f ca = sprite.getPosition();
	m_x = ca.x;
	static bool space = false;
	if(_kbhit()) 
		sprite.setTextureRect(sf::IntRect(0, 0, m_h, m_h));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { 
		if (ca.x > 0) 
			sprite.move(-0.5 * time, 0);
		sprite.setTextureRect(sf::IntRect(0, 0, m_w, m_h));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { // ���� ������ ������� ������
		if (ca.x < 514) 
			sprite.move(0.5 * time, 0);
		sprite.setTextureRect(sf::IntRect(0, 0, m_w, m_h));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if ( !space)
		{
			space = true;
			this->shoot(gameObjects);
		}
	}
	else
	{
		if (space)
		{
			space = false;
		}
	}
	
	
}



void Spaceship::draw(sf::RenderWindow& window) 
{
	window.draw(sprite);
}

void Spaceship::shoot(std::vector<std::unique_ptr<GameObject>>& gameObjects)
{
	gameObjects.push_back(std::make_unique<Shoot>("bullet.png", m_x + (m_w / 2) - 29, m_y - 70, 58, 84));
}

Spaceship::~Spaceship() = default;



Shoot::Shoot(std::string f, int x, int y, int w, int h)
{
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	File = f;
	texture.loadFromFile("texture/" + File);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, w, h));
	sprite.setPosition(x, y);
}

void Shoot::update(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects)
{

	sprite.move(0, -0.7 * time);
}

void Shoot::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

Shoot::~Shoot() = default;




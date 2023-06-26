//
// Created by Admin on 25.06.2023.


#include "Spaceship.h"
#include <algorithm>
#include <conio.h>
#include <iostream>

#include "barrier.h"
#include <vector>


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

void Spaceship::update(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects)   {

	
	sf::Vector2f ca = sprite.getPosition();
	m_x = ca.x;
	static bool space = false;
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
		if (!space)
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
	sprite.setPosition(m_x, m_y);
}

void Shoot::update(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects)
{
	sprite.move(0, -0.7 * time);

	/*for (const auto& gameObject : gameObjects) {
		if (auto barrier = dynamic_cast<Barrier*>(gameObject.get())) {
			if (sprite.getGlobalBounds().intersects(barrier->get_Sprite().getGlobalBounds())) {
				barrier->setPos(50, -165);
			}
		}
	}*/
	
}

void Shoot::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

sf::Sprite Shoot::get_Sprite()
{
	return sprite;
}

Shoot::~Shoot() = default;

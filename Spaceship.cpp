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
	for (const auto& gameObject : gameObjects) {
		if (auto barrier = dynamic_cast<Barrier*>(gameObject.get())) {
			if (sprite.getGlobalBounds().intersects(barrier->get_Sprite().getGlobalBounds())) {
				GameOver = true;
				
				break;
			}
		}
	}
	
	
}

void Spaceship::blow(sf::RenderWindow& window)
{
	sf::Vector2f ca = sprite.getPosition();
	sf::Texture expl;
	expl.loadFromFile("texture/exp2.png");
	sf::Sprite explosion(expl);
	explosion.setPosition(ca.x - 27, ca.y);

	float frameTime = 0.5f; // Интервал между кадрами анимации
	int totalFrames = 3; // Общее количество кадров анимации
	int x = 768;
	for (int currentFrame = 0; currentFrame <= totalFrames; ++currentFrame)
	{
		explosion.setTextureRect(sf::IntRect(0, x, 256, 256));
		window.draw(explosion);
		window.display();
		x -= 256;
		sf::sleep(sf::seconds(frameTime));
	}
	window.clear();
}


bool Spaceship::isGameOver()
{
	return GameOver;
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
	sf::Vector2f pos_obs = sprite.getPosition();
	bool isCollided = false; // Флаг, указывающий, было ли столкновение пули
	int se = rand() % 4;
	for (auto it = gameObjects.begin(); it != gameObjects.end(); ++it) {
		if (auto barrier = dynamic_cast<Barrier*>(it->get())) {
			if (sprite.getGlobalBounds().intersects(barrier->get_Sprite().getGlobalBounds())) {
				if (barrier->get_Type() == "rock") {
					barrier->setPos(12 * se, -165);
					isCollided = true;
					break; // Выходим из цикла, так как столкновение уже произошло
				}
				if (barrier->get_Type() == "base") {
					barrier->setPos(50 * se, -165 * 5);
					isCollided = true;
					break; // Выходим из цикла, так как столкновение уже произошло
				}
			}
		}
	}

	if (isCollided || pos_obs.y < -84) {
		// Удаляем пулю из вектора gameObjects
		gameObjects.erase(std::remove_if(gameObjects.begin(), gameObjects.end(),
			[this](const auto& obj) { return obj.get() == this; }), gameObjects.end());
	}
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

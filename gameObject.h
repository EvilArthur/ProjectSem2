#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
private:
	int m_x, m_y, m_w, m_h;
	std::string File;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	GameObject() = default;
	virtual void update(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual ~GameObject() = default;
	
};

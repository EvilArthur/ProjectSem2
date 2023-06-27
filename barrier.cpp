#include "barrier.h"
#include "Logger.h"
#include <iostream>

#include "Spaceship.h"


Barrier::Barrier(const std::string& f, int x, int y, int w, int h, const std::string& t){
    int se = rand() % 4;
	m_x = x;
    m_y = y;
    m_w = w;
    m_h = h;
    File = f;
    type = t;
    texture.loadFromFile("texture/" + File);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, w, h));
    sprite.setPosition(m_x + 100, m_y);
}


void Barrier::update(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects) {
    int se = rand() % 4;
    int se1 = rand() % 5;
    if ((this->type == "base"))
    {
        //std::cout << "base!!" << std::endl;
        sprite.move(0, 0.1 * time);
        sf::Vector2f pos_obs = sprite.getPosition();
        if (pos_obs.y > 960) {
            //se = rand() % 4;
            sprite.setPosition(m_x + 100 * se1, m_y);
        }

    }
    if ((this->type == "rock"))
    {
        //std::cout << "rock!!" << std::endl;
        sprite.move(0, 0.3 * time);
        sf::Vector2f pos_obs = sprite.getPosition();
        if (pos_obs.y > 960) {
            //se = rand() % 4;
            sprite.setPosition(m_x + 100 * se1, m_y);
        }
    }

}
std::string Barrier::get_Type() {
    return type;
}

void Barrier::draw(sf::RenderWindow& window)  {
    window.draw(sprite);
}

sf::Sprite Barrier::get_Sprite()
{
    return sprite;
}

void Barrier::setPos(int x,int y)
{
    int se = rand() % 4;
	sprite.setPosition(x + 100*se, y);
}

Barrier::~Barrier() = default;

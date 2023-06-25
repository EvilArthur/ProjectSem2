#pragma once
#include <SFML/Graphics.hpp>

class gameObject {
private:
    int x, y, w, h;
    std::string File;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

public:

    gameObject(std::string File, int x_coordinate, int y_coordinate, int w_value, int h_value);
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window){}
    virtual ~gameObject() = default;
};
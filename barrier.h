#pragma once
#include "gameObject.h";

class Barrier :public gameObject {
private:
    int x, y, w, h;
    std::string File;
    std::string type;
    sf::Image image;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Barrier(std::string File, int x_coordinate, int y_coordinate, int w_value, int h_value, std::string TYPE);
    std::string Type();
    void update(float time, std::vector<gameObject>& objects);
    void draw(sf::RenderWindow& window);
    
};
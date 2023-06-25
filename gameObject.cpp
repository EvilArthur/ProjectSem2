#include "gameObject.h"

gameObject::gameObject(std::string File, int x_coordinate, int y_coordinate, int w_value, int h_value) {
    x = x_coordinate;
    y = y_coordinate;
    w = w_value;
    h = h_value;
    image.loadFromFile(File);
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, w, h));
}
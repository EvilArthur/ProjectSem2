#include "barrier.h";

Barrier::Barrier(std::string File, int x_coordinate, int y_coordinate, int w_value, int h_value, std::string TYPE) :
    gameObject(File, x_coordinate, y_coordinate, w_value, h_value) {
    type = TYPE;
}


void Barrier::update(float time, std::vector<gameObject>& objects) {
        sprite.move(0, 0.7 * time);
    }

void Barrier::draw(sf::RenderWindow& window) {
    window.draw(sprite);
};


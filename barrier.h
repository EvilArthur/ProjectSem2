#pragma once
#include "gameObject.h"


class Barrier :public GameObject {
private:
    int m_x, m_y, m_w, m_h;
    std::string File;
    std::string type = "base";
    sf::Texture texture;
    sf::Sprite sprite;
   

public:
    Barrier(const std::string& F, int x, int y, int w, int h, const std::string& t);
    std::string get_Type();
    void update(float time, std::vector<std::unique_ptr<GameObject>>& gameObjects) override;
    void draw(sf::RenderWindow& window) override;
    sf::Sprite get_Sprite();
    void setPos(int x,int y);
    ~Barrier() override;
};

#pragma once
#include <SFML/Graphics.hpp>


class Wall {
    public:
        struct box {
            float top;
            float right;
            float bottom;
            float left;
        }; 
        Wall();
        Wall(sf::Vector2f l_pos, sf::Vector2f l_size);
        ~Wall();
        void Render(sf::RenderWindow& l_window);
        box GetBox();
    private:
        sf::RectangleShape m_wall;
        Wall::box m_box;
};
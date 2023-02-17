#pragma once
#include <SFML/Graphics.hpp>

class Wall {
    public:
        Wall();
        Wall(sf::Vector2f l_pos, sf::Vector2f l_size);
        ~Wall();
        void Render(sf::RenderWindow& l_window);
    private:
        sf::RectangleShape m_wall;
};
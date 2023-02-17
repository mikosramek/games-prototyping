#pragma once
#include "./Wall.h"

class Room {
    public:
        Room();
        ~Room();
        void Render(sf::RenderWindow& l_window);
        std::vector<Wall> GetWalls();
    private:
        std::vector<Wall> m_walls;
};

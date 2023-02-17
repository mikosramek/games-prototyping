#include "./Room.h"

Room::Room() {
    // left
    m_walls.push_back(Wall(sf::Vector2f(10, 250), sf::Vector2f(20, 500)));
    // right
    m_walls.push_back(Wall(sf::Vector2f(490, 250), sf::Vector2f(20, 500)));
    // top
    m_walls.push_back(Wall(sf::Vector2f(250, 10), sf::Vector2f(500, 20)));
    // bottom
    m_walls.push_back(Wall(sf::Vector2f(250, 490), sf::Vector2f(500, 20)));

    // room
    m_walls.push_back(Wall(sf::Vector2f(200, 100), sf::Vector2f(200, 10)));
    m_walls.push_back(Wall(sf::Vector2f(100, 200), sf::Vector2f(10, 200)));


    m_walls.push_back(Wall(sf::Vector2f(300, 400), sf::Vector2f(200, 10)));
    m_walls.push_back(Wall(sf::Vector2f(400, 300), sf::Vector2f(10, 200)));
    
}

Room::~Room() {}

void Room::Render(sf::RenderWindow& l_window) {
    for (int i = 0; i < m_walls.size(); i += 1) {
        m_walls[i].Render(l_window);
    }
}
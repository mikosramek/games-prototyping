#include "Wall.h"

Wall::Wall() {}
Wall::Wall(sf::Vector2f l_pos, sf::Vector2f l_size) {
    m_wall.setSize(l_size);
    m_wall.setOrigin(l_size.x / 2, l_size.y / 2);
    m_wall.setPosition(l_pos);
    m_wall.setFillColor(sf::Color::Red);
}
Wall::~Wall() {}

void Wall::Render(sf::RenderWindow& l_window) {
    l_window.draw(m_wall);
}
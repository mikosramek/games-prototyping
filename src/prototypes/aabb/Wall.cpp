#include "Wall.h"

Wall::Wall() {}
Wall::Wall(sf::Vector2f l_pos, sf::Vector2f l_size) {
    m_wall.setSize(l_size);
    m_wall.setOrigin(l_size.x / 2, l_size.y / 2);
    m_wall.setPosition(l_pos);
    m_wall.setFillColor(sf::Color::Red);

    m_box.top = l_pos.y - l_size.y / 2;
    m_box.right = l_pos.x + l_size.x / 2;
    m_box.bottom = l_pos.y + l_size.y / 2;
    m_box.left = l_pos.x - l_size.x / 2;
}
Wall::~Wall() {}

void Wall::Render(sf::RenderWindow& l_window) {
    l_window.draw(m_wall);
}

Wall::box Wall::GetBox() {
    return m_box;
}
/*
    Name: AABB
    Purpose: Demonstrate AABB collision between a player and a group of boxes.
    Stretch Goals: Allow for configurable rooms, that the player can "move" between.

    Room - a room contains walls, will render the Walls
    Wall - a rectangle to provide collision, will render itself
    Player - a square that can move up/right/down/left and will collide with Walls in the current Room
*/
#include "./AABB.h"


AABB::AABB() {
    std::cout << "New AABB" << std::endl;
    m_shouldRender = true;
}

AABB::~AABB() {}

void AABB::Render(sf::RenderWindow& l_window) {
    m_player.Render(l_window);
    m_room.Render(l_window);
}

void AABB::Tick(sf::Event& event) {
    m_player.Tick();
}
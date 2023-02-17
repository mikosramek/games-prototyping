#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "./Room.h"

class Player {
    public:
        Player();
        ~Player();
        void Render(sf::RenderWindow& l_window);
        void Tick();
        void SetRoom(Room* l_room);
    private:
        sf::RectangleShape m_self;
        sf::Vector2f m_pos;
        sf::Vector2f m_inputs;
        int m_size;
        void HandleInputs();
        void NormalizeInput();
        void CheckForCollisions();
        void ApplyInput();
        float speed;
        Room* m_currentRoom;
};

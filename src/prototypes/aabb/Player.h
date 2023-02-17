#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class Player {
    public:
        Player();
        ~Player();
        void Render(sf::RenderWindow& l_window);
        void Tick();
    private:
        sf::RectangleShape m_self;
        sf::Vector2f m_pos;
        sf::Vector2f m_inputs;
        void HandleInputs();
        void NormalizeInput();
        void CheckForCollisions();
        void ApplyInput();
        float speed;
};

#include "./Player.h"

Player::Player() {
    m_pos = sf::Vector2f(250, 250);
    m_self = sf::RectangleShape(sf::Vector2f(50, 50));
    m_self.setOrigin(25, 25);
    m_self.setPosition(m_pos);
    m_self.setFillColor(sf::Color::Green);

    speed = 0.1;
};

Player::~Player() {};

void Player::Render(sf::RenderWindow& l_window) {
    l_window.draw(m_self);
}

void Player::HandleInputs() {
    // get input vector
    m_inputs = sf::Vector2f(0, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_inputs.x -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_inputs.x += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_inputs.y -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_inputs.y += 1;
    }

}

void Player::NormalizeInput() {
    // get magnitude of vector
    float magnitude = sqrt(m_inputs.x * m_inputs.x + m_inputs.y * m_inputs.y);
    // divide each component by it's magnitude (don't divide if it's 0)
    if (magnitude > 0) {
        m_inputs.x = m_inputs.x / magnitude;
        m_inputs.y = m_inputs.y / magnitude;
    }
}

void Player::CheckForCollisions() {
    // go through list of walls
    // if current position + m_inputs (x/y separately) would collide - make that axis 0
}

void Player::ApplyInput() {
    m_pos += m_inputs * speed;
    m_self.setPosition(m_pos);
}

void Player::Tick() {
    HandleInputs();
    NormalizeInput();
    ApplyInput();
}

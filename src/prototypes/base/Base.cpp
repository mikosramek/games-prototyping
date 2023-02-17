#include "./Base.h"

Base::Base() {
    m_shouldRender = false;
};
Base::~Base() {};

bool Base::ShouldRender() { return m_shouldRender; }
void Base::Render(sf::RenderWindow& l_window) {}

void Base::Tick(sf::Event& event) { }
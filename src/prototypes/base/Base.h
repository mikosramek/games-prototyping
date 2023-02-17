#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../shared/Window.h"

class Base {
    public:
        Base();
        ~Base();
        virtual void Render(sf::RenderWindow& l_window);
        virtual bool ShouldRender();
        virtual void Tick(sf::Event& event);
    protected:
        bool m_shouldRender;
};

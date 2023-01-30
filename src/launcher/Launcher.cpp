#include "Launcher.h"


Launcher::Launcher():
    m_window("SFML Prototypes", sf::Vector2u(800, 600)),
    m_currentPrototype("-", sf::Vector2u(500, 500))
{
    m_currentPrototype.Hide();

    m_prototypes.push_back("AABB");
    m_prototypes.push_back("Gravity");
    m_prototypes.push_back("Animation");
    m_prototypes.push_back("Scrolling Backgrounds");

    m_index = 0;

    if (!m_font.loadFromFile("resources/Heebo-Regular.ttf"))
    {
        // error...
    }
};

Launcher::~Launcher() { };


Window* Launcher::GetWindow() {
    return &m_window;
}

void Launcher::Render() {
    sf::Text text;
    text.setFont(m_font);
    text.setString(std::to_string(m_index + 1) + ": " + m_prototypes[m_index]);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);

    m_window.BeginDraw();
        m_window.Draw(text);
    m_window.EndDraw();

    m_currentPrototype.BeginDraw();
    // pass window to game object to render with
    m_currentPrototype.EndDraw();
}

void Launcher::Tick() {
    sf::Event event = m_window.Tick();
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            AdjustIndex(-1);
        }
        else if (event.key.code == sf::Keyboard::Down) {
            AdjustIndex(1);
        } else if (event.key.code == sf::Keyboard::P) {
            OpenPrototype();
        }
    }


    m_currentPrototype.Tick();
    if (m_currentPrototype.IsDone()) {
        m_currentPrototype.Hide();
    }
}

void Launcher::AdjustIndex(int l_change) {
    m_index += l_change;
    if (m_index < 0) {
        m_index = m_prototypes.size() - 1;
    } else if (m_index >= m_prototypes.size()) {
        m_index = 0;
    }
}

void Launcher::OpenPrototype() {
    m_currentPrototype.Show();
}
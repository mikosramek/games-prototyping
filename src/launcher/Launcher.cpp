#include "Launcher.h"

Launcher::Launcher():
    m_window("SFML Prototypes", sf::Vector2u(800, 600)),
    m_currentPrototype("-", sf::Vector2u(500, 500)),
    m_prototype()
{
    ResetPrototype();

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

void Launcher::ResetPrototype() {
    m_currentPrototype.Hide();
    m_prototype = new Base();
}

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
        if (m_prototype->ShouldRender()) {
            m_prototype->Render(*m_currentPrototype.GetRenderWindow());
        }
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
        } else if (event.key.code == sf::Keyboard::Space) {
            OpenPrototype();
        }
    }


    sf::Event protoEvent = m_currentPrototype.Tick();
    if (m_prototype->ShouldRender()) {
        m_prototype->Tick(protoEvent);
    }
    if (m_currentPrototype.IsDone()) {
        ResetPrototype();
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
    std::cout << "Launching prototype" << std::endl;
    bool validSelection = true;
    switch(m_index) {
        case 0: {
            m_prototype = new AABB();
            break;
        }
        default:
            validSelection = false;
            break;
    }
    if (validSelection) {
        m_currentPrototype.Show(m_prototypes[m_index]);
    }
}
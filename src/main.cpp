#include <SFML/Graphics.hpp>
#include "launcher/Launcher.h"

int main()
{
    // auto window = sf::RenderWindow{ { 1920u, 1080u }, "SFML Prototypes" };
    // window.setFramerateLimit(144);

    Launcher launcher;

    while (!launcher.GetWindow()->IsDone()) {
        launcher.Render();
        launcher.Tick();
    }
}
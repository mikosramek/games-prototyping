#pragma once
#include "../shared/Window.h"


class Launcher
{
    public:
        Launcher();
        ~Launcher();
        Window* GetWindow();

        void Render();
        void Tick();
        void OpenPrototype();
    private:
        sf::Font m_font;

        Window m_window;
        Window m_currentPrototype;
        std::vector<std::string> m_prototypes;
        int m_index;
        void AdjustIndex(int l_change);
};

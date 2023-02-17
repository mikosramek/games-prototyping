#pragma once
#include <iostream>
#include "../shared/Window.h"
#include "../prototypes/base/Base.h"
#include "../prototypes/aabb/AABB.h"

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
        Base* m_prototype;

        std::vector<std::string> m_prototypes;
        int m_index;
        void AdjustIndex(int l_change);
        void ResetPrototype();
};

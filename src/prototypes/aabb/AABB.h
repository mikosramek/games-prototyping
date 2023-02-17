#pragma once
#include "../base/Base.h"
#include "./Room.h"
#include "./Player.h"

class AABB: public Base {
    public:
        AABB();
        ~AABB();
        void Render(sf::RenderWindow& l_window);
        void Tick(sf::Event& event);
    private:
        Room m_room;
        Player m_player;
};

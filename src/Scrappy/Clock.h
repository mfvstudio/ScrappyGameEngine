//
// Created by mario flores on 12/16/25.
//


#include <SFML/System/Clock.hpp>

namespace Scrappy
{
    class Clock
    {
    private:
        sf::Clock m_Clock;
    public:
        Clock() = default;
        ~Clock() = default;
        sf::Time GetDeltaTime();
    };
}


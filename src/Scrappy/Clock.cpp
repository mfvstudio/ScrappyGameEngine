//
// Created by mario flores on 12/16/25.
//

#include "Clock.h"

#include <SFML/System/Time.hpp>

namespace Scrappy
{
    sf::Time Clock::GetDeltaTime()
    {
        return m_Clock.restart();
    }

}

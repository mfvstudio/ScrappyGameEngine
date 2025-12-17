//
// Created by mario flores on 12/17/25.
//

#include "SFMLInput.h"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>


namespace Scrappy
{
    Input* Input::s_Instance = new SFMLInput();

    bool SFMLInput::IsKeyPressedImpl(Key keycode)
    {
        return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(keycode));
    }

    bool SFMLInput::IsMouseButtonPressedImpl(int btn)
    {
        return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(btn));
    }

    std::pair<float, float> SFMLInput::GetMousePosImpl()
    {
        auto pos = sf::Mouse::getPosition();
        return {static_cast<float>(pos.x), static_cast<float>(pos.y)};
    }
}

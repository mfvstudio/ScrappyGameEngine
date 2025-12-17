//
// Created by mario flores on 12/17/25.
//
#pragma once
#include "Input.h"

namespace Scrappy
{
    class SFMLInput: public Input
    {
    protected:
        bool IsKeyPressedImpl(Key keycode) override;
        bool IsMouseButtonPressedImpl(int btn) override;
        std::pair<float, float> GetMousePosImpl() override;
    };

}
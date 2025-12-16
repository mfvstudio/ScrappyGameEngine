//
// Created by mario flores on 12/1/25.
//
#pragma once

#include <string>

#include "Core.h"
#include "Events/Event.h"


namespace Scrappy
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width, Height;
        WindowProps(const std::string& title = "ScrappyDemo", const unsigned int w = 1920, const unsigned h = 1080)
            :  Title(title), Width(w), Height(h) {}
    };

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;
        virtual ~Window() = default;
        virtual void OnUpdate() = 0;
        virtual void Display() = 0;
        virtual void* GetRenderer() = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& cb) = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}

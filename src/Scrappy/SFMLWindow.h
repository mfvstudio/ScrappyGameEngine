//
// Created by mario flores on 12/1/25.
//

#pragma once
#include "Window.h"
#include <SFML/Graphics.hpp>

namespace Scrappy
{
    class SFMLWindow : public Window
    {
    private:
        sf::RenderWindow m_Window;
        struct SFMLWindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;
            EventCallbackFn EventCallback;
        };
        SFMLWindowData m_Data;
    public:
        SFMLWindow(const WindowProps& props);
        virtual ~SFMLWindow();
        void OnUpdate() override;
        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventCallbackFn& cb) override {m_Data.EventCallback = cb;};
    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
        //Maps SFML Events to our custom events
        virtual void MapEvents(const sf::Event& e);
    };
}
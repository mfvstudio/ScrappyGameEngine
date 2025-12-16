//
// Created by mario flores on 11/21/25.
//

#ifndef SCRAPPY_APPLICATION_H
#define SCRAPPY_APPLICATION_H

#pragma once
#include <memory>

#include "Layer.h"
#include "LayerStack.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "Clock.h"

namespace Scrappy
{
    class Application
    {

    public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& e);
        void Pushlayer(Layer* layer);
        void PushOverlay(Layer* layer);
        inline static Application& GetInstance() { return *s_Instance;}
        inline std::unique_ptr<Window>& GetWindow() { return m_Window; }
        Scrappy::Clock Clock;
    private:
        std::unique_ptr<Window> m_Window;
        bool OnWindowClose(WindowCloseEvent& e);
        bool m_IsRunning = true;
        LayerStack m_LayerStack;
        static Application* s_Instance;
    };
    //Should be defined in client
    Application* CreateApp();
}


#endif //SCRAPPY_APPLICATION_H
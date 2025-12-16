//
// Created by mario flores on 11/21/25.
//

#ifndef SCRAPPY_APPLICATION_H
#define SCRAPPY_APPLICATION_H

#pragma once
#include <memory>

#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace Scrappy
{
    class Application
    {
    public:
        Application();
        virtual ~Application();
        void Run();
        void OnEvent(Event& e);
    private:
        std::unique_ptr<Window> m_Window;
        bool OnWindowClose(WindowCloseEvent& e); //TODO change Event to WindowCLoseEvent
        bool m_IsRunning = true;
    };
    //Should be defined in client
    Application* CreateApp();
}


#endif //SCRAPPY_APPLICATION_H
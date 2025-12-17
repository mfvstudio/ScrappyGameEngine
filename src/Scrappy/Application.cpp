//
// Created by mario flores on 11/21/25.
//

#include "Application.h"

#include "Input.h"
#include "Logger.h"
#include "Events/ApplicationEvent.h"

namespace Scrappy
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
    Application* Application::s_Instance = nullptr;
    Application::Application()
    {
        s_Instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
    }
    Application::~Application()
    {
    }
    void Application::Run()
    {
        while (m_IsRunning) {
            m_Window->OnUpdate();
            for (Layer* layer : m_LayerStack) {
                layer->OnUpdate();
            }
            //The window can be Closed before this call, leading to an assertion failure.
            if (m_IsRunning) {
                m_Window->Display();
            } else {
                m_Window->ShutDown();
            }
        }
    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
            (*--it)->OnEvent(e);
            if (e.Handled) break;
        }
    }
    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_IsRunning = false;
        return false;
    }

    void Application::Pushlayer(Layer* layer)
    {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer)
    {
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }
}

//
// Created by mario flores on 12/16/25.
//
#pragma once
#include "../Layer.h"

#include "../Application.h"
#include "../Events/KeyEvent.h"
#include "../Events/MouseEvent.h"

namespace Scrappy
{
    class ImGuiLayer : public Layer
    {
    private:
        float m_Time = 0.0f;
    public:
        ImGuiLayer();
        ~ImGuiLayer();
        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate() override;
        void OnEvent(Event &e) override;
    private:
        bool OnMouseMoveEvent(MouseMovedEvent& e);
        bool OnMouseWheelEvent(MouseScrolledEvent& e);
        bool OnMousePressedEvent(MouseButtonPressedEvent& event);
        bool OnMouseReleasedEvent(MouseButtonReleasedEvent& event);
        bool OnKeyPressedEvent(KeyPressedEvent& event);
        bool OnKeyReleasedEvent(KeyReleasedEvent& event);
        bool OnKeyTypedEvent(KeyTypedEvent& event);
        bool OnWindowCloseEvent(WindowCloseEvent& e);
        bool OnWindowResizeEvent(WindowResizeEvent& e);
        bool OnWindowFocusEvent(WindowFocusEvent& e);
        bool OnWindowLostFocusEvent(WindowLostFocusEvent& e);

    };
}

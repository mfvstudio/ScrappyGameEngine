//
// Created by mario flores on 12/16/25.
//
#pragma once
#include "../Layer.h"

#include "../Application.h"
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
        bool OnMouseMove(MouseMovedEvent& e);
    };
}

//
// Created by mario flores on 12/16/25.
//
#include "ImGuiLayer.h"
#include "imgui-SFML.h"
#include "imgui.h"
#include "imgui_internal.h"
#include "../Events/MouseEvent.h"


namespace Scrappy
{
#define IMGUI_BIND(x) std::bind(&ImGuiLayer::x, this, std::placeholders::_1)
    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer")
    {
    }

    ImGuiLayer::~ImGuiLayer()
    {
    }

    void ImGuiLayer::OnAttach()
    {
        auto& app = Scrappy::Application::GetInstance();
        auto* win = static_cast<sf::RenderWindow*>(app.GetWindow()->GetRenderer());
        ImGui::SFML::Init(*win);
    }
    void ImGuiLayer::OnDetach()
    {

    }
    void ImGuiLayer::OnUpdate()
    {
        auto& app = Scrappy::Application::GetInstance();
        auto* win = static_cast<sf::RenderWindow*>(app.GetWindow()->GetRenderer());
        ImGui::SFML::Update(*win, app.Clock.GetDeltaTime());
        ImGui::ShowDemoWindow();
        ImGui::SFML::Render(*win);
    }
    void ImGuiLayer::OnEvent(Event &e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<MouseMovedEvent>(IMGUI_BIND(OnMouseMove));
    }

    bool ImGuiLayer::OnMouseMove(MouseMovedEvent& e)
    {
        ImGui::GetIO().AddMousePosEvent(e.GetX(), e.GetY()); //TODO: Determine if there is another way of setting events.
        return false;
    }
    //TODO: Add the rest of the ImGui Events.
}

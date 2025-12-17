//
// Created by mario flores on 12/1/25.
//

#include "SFMLWindow.h"
#include <SFML/Graphics.hpp>
#include "Logger.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

namespace Scrappy
{
    Window* Window::Create(const WindowProps& props)
    {
        return new SFMLWindow(props);
    }
    SFMLWindow::SFMLWindow(const WindowProps& props)
    {
        Init(props);
    }
    SFMLWindow::~SFMLWindow()
    {
    }
    void SFMLWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;
        m_Window = sf::RenderWindow(sf::VideoMode({m_Data.Width, m_Data.Height}), m_Data.Title);
    }
    void SFMLWindow::ShutDown()
    {
        m_Window.close();
    }
    void SFMLWindow::OnUpdate()
    {
        m_Window.clear();
        m_Window.handleEvents([this](const auto& e) {MapEvents(e);});
    }

    void SFMLWindow::Display()
    {
        m_Window.display();
    }


    //SFML Events https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1Event.html
    void SFMLWindow::MapEvents(const sf::Event &e)
    {
        //-------------Window Events
        if (e.is<sf::Event::Closed>()) {
            WindowCloseEvent windowCloseEvent;
            m_Data.EventCallback(windowCloseEvent);
        }
        else if (const auto* resized = e.getIf<sf::Event::Resized>()) {
            WindowResizeEvent windowResizeEvent(resized->size.x, resized->size.y);
            m_Data.EventCallback(windowResizeEvent);
        }
        else if (e.is<sf::Event::FocusGained>()) {
            WindowFocusEvent windowFocusEvent;
            m_Data.EventCallback(windowFocusEvent);
        }
        else if (e.is<sf::Event::FocusLost>()) {
            WindowLostFocusEvent windowLostFocusEvent;
            m_Data.EventCallback(windowLostFocusEvent);
        }
        else if (const auto* keyPressed = e.getIf<sf::Event::KeyPressed>()) {
            KeyPressedEvent windowKeyPressEvent(static_cast<int>(keyPressed->code), 0);
            m_Data.EventCallback(windowKeyPressEvent);
        }
        else if (const auto* keyReleased = e.getIf<sf::Event::KeyReleased>()) {
            KeyReleasedEvent windowKeyReleasedEvent(static_cast<int>(keyReleased->code));
            m_Data.EventCallback(windowKeyReleasedEvent);
        }
        else if (const auto* textEntered = e.getIf<sf::Event::TextEntered>()) {
            KeyTypedEvent windowKeyTypedEvent(textEntered->unicode);
            m_Data.EventCallback(windowKeyTypedEvent);
        }
        else if (const auto* mouseMoved = e.getIf<sf::Event::MouseMoved>()) {
            MouseMovedEvent windowMouseMovedEvent(mouseMoved->position.x, mouseMoved->position.y);
            m_Data.EventCallback(windowMouseMovedEvent);
        }
        else if (const auto* mouseScrolled = e.getIf<sf::Event::MouseWheelScrolled>()) {
            MouseScrolledEvent scrolledEvent(mouseScrolled->position.x, mouseScrolled->position.y);
            m_Data.EventCallback(scrolledEvent);
        }
        else if (const auto* mouseButtonPressed = e.getIf<sf::Event::MouseButtonPressed>()) {
            MouseButtonPressedEvent pressedEvent(static_cast<int>(mouseButtonPressed->button));
            m_Data.EventCallback(pressedEvent);
        }
        else if (const auto* mouseButtonReleased = e.getIf<sf::Event::MouseButtonReleased>()) {
            MouseButtonReleasedEvent releasedEvent(static_cast<int>(mouseButtonReleased->button));
            m_Data.EventCallback(releasedEvent);
        }
    }


}

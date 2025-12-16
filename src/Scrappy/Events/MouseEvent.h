//
// Created by mario flores on 11/29/25.
//
#pragma once
#include "Event.h"
#include <sstream>

namespace Scrappy
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent( const float x, const float y ) : m_MouseX(x), m_MouseY(y) {}
        inline float GetX() {return m_MouseX;}
        inline float GetY() {return m_MouseY;}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
            return ss.str();
        }
    EVENT_CLASS_TYPE(MouseMoved)
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float m_MouseX, m_MouseY;
    };

    class MouseScrolledEvent : public Event
    {
        private:
            float m_XOffset, m_YOffset;
        public:
            MouseScrolledEvent(float xOffSet, float yOffSet) : m_XOffset(xOffSet), m_YOffset(yOffSet) {}
            inline float GetXOffset() {return m_XOffset;}
            inline float GetYOffset() {return m_YOffset;}
            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
                return ss.str();
            }
        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class MouseButtonEvent : public Event
    {
    protected:
        int m_Button;
        MouseButtonEvent(const int btn) : m_Button(btn) {}
    public:
        inline int GetMouseButton() const { return m_Button; }
        EVENT_CLASS_CATEGORY(EventCategoryMouseButton | EventCategoryInput)
    };

    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(const int btn) : MouseButtonEvent(btn) {}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonPressed)
    };
    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
        public:
        MouseButtonReleasedEvent(const int btn) : MouseButtonEvent(btn) {}
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }
        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}
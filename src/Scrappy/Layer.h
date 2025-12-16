//
// Created by mario flores on 12/15/25.
//
#pragma once
#include <string>
#include "Events/Event.h"

namespace Scrappy
{
    class Layer
    {
    public:
        Layer(const std::string& name = "Layer") : m_Name(name) {}
        virtual ~Layer();
        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate() {}
        virtual void OnEvent(Event& e) {}

        inline const std::string& GetName() const { return m_Name; }
    protected:
        std::string m_Name;
    };
}
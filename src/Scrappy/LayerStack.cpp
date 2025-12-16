//
// Created by mario flores on 12/15/25.
//

#include "LayerStack.h"

namespace Scrappy
{
    LayerStack::LayerStack()
    {
        m_LayerInsert = m_Layers.begin();
    }

    LayerStack::~LayerStack()
    {
        for (Layer* layer : m_Layers) {
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* layer)
    {
        m_LayerInsert = m_Layers.emplace(m_LayerInsert, layer);
    }

    void LayerStack::PushOverlay(Layer *overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer *layer)
    {
        if (const auto it = std::find(m_Layers.begin(), m_Layers.end(), layer); it != m_Layers.end()) {
            m_Layers.erase(it);
            --m_LayerInsert;
        }
    }

    void LayerStack::PopOverlay(Layer *layer)
    {
        if (const auto it = std::find(m_Layers.begin(), m_Layers.end(), layer); it != m_Layers.end()) {
            m_Layers.erase(it);
        }
    }

}
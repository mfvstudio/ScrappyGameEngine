//
// Created by mario flores on 11/21/25.
//

#ifndef SCRAPPY_ENTRYPOINT_H
#define SCRAPPY_ENTRYPOINT_H
#include "Logger.h"
#include "layers/ImGuiLayer.h"

#endif //SCRAPPY_ENTRYPOINT_H

extern Scrappy::Application* Scrappy::CreateApp();

int main(int argc, char** argv)
{
    Scrappy::Logger::Init();
    Scrappy_WARN("Initialized Logger.");
    CLIENT_WARN("Hello from Client Logger!");
    const auto app = Scrappy::CreateApp();
    app->PushOverlay(new Scrappy::ImGuiLayer());
    app->Run();
    delete app;
}



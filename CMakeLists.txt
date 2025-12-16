cmake_minimum_required(VERSION 4.0)
project(Scrappy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

find_package(SFML 3.0.2 COMPONENTS Graphics Window System Audio REQUIRED)


add_library(Scrappy STATIC
        include/Scrappy.h
        src/Scrappy/Application.cpp
        src/Scrappy/Application.h
        src/Scrappy/Core.cpp
        src/Scrappy/Core.h
        src/Scrappy/EntryPoint.h
        src/Scrappy/Logger.cpp
        src/Scrappy/Logger.h
        src/Scrappy/Events/Event.h
        src/Scrappy/Events/KeyEvent.h
        src/Scrappy/Events/MouseEvent.h
        src/Scrappy/Events/ApplicationEvent.h
        src/Scrappy/Window.h
        src/Scrappy/SFMLWindow.cpp
        src/Scrappy/SFMLWindow.h
        src/Scrappy.h
        src/Scrappy/Layer.cpp
        src/Scrappy/Layer.h
        src/Scrappy/LayerStack.cpp
        src/Scrappy/LayerStack.h
)
target_link_libraries(Scrappy PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio
    PUBLIC spdlog)
target_include_directories(Scrappy PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
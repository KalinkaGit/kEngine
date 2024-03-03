#include <iostream>
#include <windows.h>
#include <unistd.h>

#include "Window/Window.hpp"

int main(void)
{
    kEngine::Window window("kEngine", kEngine::State::Windowed, 1200, 600);

    while (!window.shouldClose())
    {
        window.display();
        window.setTitle("kEngine v2.0");
    }

    window.terminate();
    
    return 0;
}

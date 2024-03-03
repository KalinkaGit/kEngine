/**
 * @file State.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-21
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Window/Window.hpp"

namespace kEngine
{
    void Window::setState(State state)
    {
        if (state == State::Fullscreen)
        {
            const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            glfwSetWindowMonitor(m_window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
        }
        else if (state == State::Windowed)
        {
            std::pair<float, float> size = getSize();
            glfwSetWindowMonitor(m_window, nullptr, 0, 0, size.first, size.second, 0);
        }
        else if (state == State::Borderless)
        {
            const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            glfwSetWindowMonitor(m_window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
        }

        m_state = state;
    }

    State Window::getState() const
    {
        return m_state;
    }
}
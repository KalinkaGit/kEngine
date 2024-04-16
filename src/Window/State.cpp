/**
 * @file State.cpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Methods to manage the state (border...) of the window
 * @version 1.0.0
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024 (jk)
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
            Vec2i size = getSize();
            glfwSetWindowMonitor(m_window, nullptr, 0, 0, size.x, size.y, 0);
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
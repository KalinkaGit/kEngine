/**
 * @file Position.cpp
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
    void Window::setPosition(float x, float y)
    {
        glfwSetWindowPos(m_window, x, y);
    }

    std::pair<float, float> Window::getPosition() const
    {
        int x, y;

        glfwGetWindowPos(m_window, &x, &y);

        return {x, y};
    }
}

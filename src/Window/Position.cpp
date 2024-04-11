/**
 * @file Position.cpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Methods to manage the position of the window
 * @version 1.0.0
 * @date 2024-04-11
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

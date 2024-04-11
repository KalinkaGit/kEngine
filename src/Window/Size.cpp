/**
 * @file Size.cpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Methods to manage the size of the window
 * @version 1.0.0
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Window/Window.hpp"

namespace kEngine
{
    void Window::setSize(float width, float height)
    {
        if (width < 0 || height < 0)
        {
            throw std::runtime_error("Width and height must be positive");
        }

        glfwSetWindowSize(m_window, width, height);
    }

    std::pair<float, float> Window::getSize() const
    {
        int width, height;

        glfwGetWindowSize(m_window, &width, &height);

        return {width, height};
    }
}

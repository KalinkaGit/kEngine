/**
 * @file Size.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-20
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

/**
 * @file Visible.cpp
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
    bool Window::isVisible() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_VISIBLE);
    }

    void Window::hide()
    {
        glfwHideWindow(m_window);
    }

    void Window::show()
    {
        glfwShowWindow(m_window);
    }

    void Window::setVisible()
    {
        if (isVisible())
        {
            hide();
        }
        else
        {
            show();
        }
    }

    void Window::setVisible(bool visible)
    {
        if (visible)
        {
            show();
        }
        else
        {
            hide();
        }
    }
}

/**
 * @file Visible.cpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Methods to manage the visibility of the window
 * @version 1.0.0
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024 (jk)
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

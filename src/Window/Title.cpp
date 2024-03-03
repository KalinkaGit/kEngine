/**
 * @file Title.cpp
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
    void Window::setTitle(const std::string &title)
    {
        glfwSetWindowTitle(m_window, title.c_str());
    }

    std::string Window::getTitle() const
    {
        return m_title;
    }
}

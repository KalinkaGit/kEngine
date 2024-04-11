/**
 * @file Title.cpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Methods to manage the title of the window
 * @version 1.0.0
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024 (jk)
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

/**
 * @file Window.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Window/Window.hpp"

namespace kEngine
{
    Window::Window(const std::string &title, State state, float width, float height)
        : m_state(state), m_title(title), m_frameLimit(0)
    {
        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        glfwWindowHint(GLFW_SAMPLES, 16);

        m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!m_window)
        {
            glfwTerminate();
            throw std::runtime_error("Failed to create window");
        }

        glfwMakeContextCurrent(m_window);

        if (m_state == State::Fullscreen)
        {
            const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            glfwSetWindowMonitor(m_window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
        }

        glfwSwapInterval(0);

        glfwSetWindowSizeCallback(m_window, [](GLFWwindow *window, int width, int height) {
            Window *win = static_cast<Window *>(glfwGetWindowUserPointer(window));
            win->setSize(width, height);
        });

        glfwSetWindowUserPointer(m_window, this);

        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow *window, int width, int height) {
            glViewport(0, 0, width, height);
        });

        glViewport(0, 0, width, height);

        setFrameLimit(0);
    }

    Window::~Window()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(m_window);
    }

    void Window::display()
    {
        swapBuffers();
        pollEvents();
        
        if (m_frameLimit > 0)
        {
            Time time = m_clock.getElapsedTime();
            float sleepTime = m_frameLimit - time.asMilliseconds();

            if (sleepTime > 0)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(sleepTime)));
            }

            m_clock.restart();
        }
    }

    bool Window::shouldClose() const
    {
        return glfwWindowShouldClose(m_window);
    }

    void Window::close()
    {
        glfwSetWindowShouldClose(m_window, true);
    }

    unsigned int Window::getFrameLimit() const
    {
        return (m_frameLimit);
    }

    void Window::setFrameLimit(unsigned int limit)
    {
        m_frameLimit = limit;
    }

    void Window::terminate(void)
    {
        glfwTerminate();
    }

    void Window::pollEvents()
    {
        glfwPollEvents();
    }

    void Window::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}

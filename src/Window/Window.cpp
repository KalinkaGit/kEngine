/**
 * @file Window.cpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Main methods to manage the window
 * @version 1.0.0
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024 (jk)
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
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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
        glfwSetCursorPosCallback(m_window, [](GLFWwindow *window, double xpos, double ypos) {
            Window *win = static_cast<Window *>(glfwGetWindowUserPointer(window));
            win->m_cursorPos = Vec2f(xpos, ypos);
        });

        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow *window, int width, int height) {
            glViewport(0, 0, width, height);
        });

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }

        glViewport(0, 0, width, height);

        glEnable(GL_MULTISAMPLE);
        glEnable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

    Window::Win *Window::getWindow() const
    {
        return m_window;
    }

    Vec2f Window::getCursorPos() const
    {
        return m_cursorPos;
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

    bool Window::isKeyPressed(int key) const
    {
        return glfwGetKey(m_window, key) == GLFW_PRESS;
    }

    void Window::setClearColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
    }

    void Window::clear()
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::setCursorMode(int mode)
    {
        glfwSetInputMode(m_window, GLFW_CURSOR, mode);
    }
}

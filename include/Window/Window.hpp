/**
 * @file Window.hpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Header of the window class
 * @version 1.0.0
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>
#include <iostream>
#include <thread>

#include "Window/State.hpp"
#include "Clock/Clock.hpp"
#include "Utils/Vectors.hpp"

namespace kEngine
{
    class Window
    {
        public:
            /**
             * @brief Construct a new window object
             * 
             * @param title Title of the window
             * @param state State of the window (windowed or fullscreen)
             * @param width Width of the window
             * @param height Height of the window
             */
            Window(const std::string &title, State state, float width, float height);

            /**
             * @brief Destroy the window object
             */
            virtual ~Window();

            /**
             * @brief Display the window
             */
            void display();

            /**
             * @brief Indicate whether the window should close
             */
            bool shouldClose() const;

            /**
             * @brief Swap the buffers of the window
             */
            void swapBuffers();

            /**
             * @brief Poll the events of the window
             */
            void pollEvents();

            /**
             * @brief Clear the window
             */
            void clear();

            /**
             * @brief Close the window
             */
            void close();

            /**
             * @brief Get the width of the window
             * 
             * @return float Width of the window
             */
            float getWidth() const;

            /**
             * @brief Get the height of the window
             * 
             * @return float Height of the window
             */
            float getHeight() const;

            /**
             * @brief Set the position of the window
             * 
             * @param x X position of the window
             * @param y Y position of the window
             */
            void setPosition(float x, float y);

            /**
             * @brief Get the position of the window
             * 
             * @return Vec2i Position of the window
             */
            Vec2i getPosition() const;

            /**
             * @brief Get the title of the window
             * 
             * @return std::string Title of the window
             */
            std::string getTitle() const;

            /**
             * @brief Get the frame limit of the window
             * 
             * @return unsigned int Frame limit of the window
             */
            unsigned int getFrameLimit() const;

            /**
             * @brief Set the size of the window
             * 
             * @param width Width of the window
             * @param height Height of the window
             */
            void setSize(float width, float height);

            /**
             * @brief Get the size of the window
             * 
             * @return Vec2i Size of the window
             */
            Vec2i getSize() const;

            /**
             * @brief Set the title of the window
             * 
             * @param title Title of the window
             */
            void setTitle(const std::string &title);

            /**
             * @brief Set the state of the window
             * 
             * @param state State of the window (windowed or fullscreen)
             */
            void setState(State state);

            /**
             * @brief Get the state of the window
             * 
             * @return true Window is fullscreen
             * @return false Window is windowed
             */
            State getState() const;

            /**
             * @brief Set the frame limit of the window
             * 
             * @param frameLimit Frame limit of the window
             */
            void setFrameLimit(unsigned int frameLimit);

            /**
             * @brief Set the visibility of the window
             * @details If no parameter is passed, the visibility of the window is toggled
             * 
             * @param visible Visibility of the window
             */
            void setVisible();
            void setVisible(bool visible);

            /**
             * @brief Get the visibility of the window
             * 
             * @return bool Visibility of the window
             */
            bool isVisible() const;

            /**
             * @brief Terminate the window
             */
            void terminate();

            /**
             * @brief Get the window
             * 
             * @return Win* Pointer to the window
             */
            GLFWwindow *getWindow() const;

            bool isKeyPressed(int key) const;

        private:
            State m_state;
            unsigned int m_frameLimit;
            std::string m_title;
            Clock m_clock;
            GLFWwindow *m_window;

            /**
             * @brief Hide the window
             */
            void hide();

            /**
             * @brief Show the window
             */
            void show();
    };
}

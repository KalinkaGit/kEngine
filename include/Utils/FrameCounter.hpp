/**
 * @file FrameCounter.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <iostream>

#include "Clock/Clock.hpp"

namespace kEngine
{
    class FrameCounter
    {
        public:
            /**
             * @brief Construct a new Frame Counter object
             */
            FrameCounter();

            /**
             * @brief Update the frame counter
             */
            void update();

            /**
             * @brief Get the FPS
             * 
             * @return int FPS
             */
            int getFPS() const;

            /**
             * @brief Print the FPS
             */
            void printFPS() const;

        private:
            Clock m_clock;
            int m_frameCount;
            int m_fps;
    };
}

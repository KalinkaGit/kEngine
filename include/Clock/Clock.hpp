/**
 * @file Clock.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <chrono>

#include "Time.hpp"

namespace kEngine
{
    class Clock
    {
        public:
            /**
             * @brief Construct a new Clock object
             */
            Clock();
            ~Clock() = default;

            /**
             * @brief Restart the clock
             */
            void restart();
            
            /**
             * @brief Get the elapsed time since the last restart
             * 
             * @return Time The elapsed time
             */
            Time getElapsedTime() const;

            /**
             * @brief TimePoint is a type alias for a time point which is a very long and complicated type in the standard library
             */
            using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock>;
        
        private:
            TimePoint m_start;
    };
}

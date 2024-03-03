/**
 * @file Clock.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Clock/Clock.hpp"

namespace kEngine
{
    Clock::Clock()
    {
        restart();
    }

    void Clock::restart()
    {
        m_start = std::chrono::high_resolution_clock::now();
    }

    Time Clock::getElapsedTime() const
    {
        const auto now = std::chrono::high_resolution_clock::now();
        const auto elapsed = now - m_start;

        return Time(std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count());
    }
}
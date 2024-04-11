/**
 * @file Clock.cpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Main methods to manage a clock
 * @version 1.0.0
 * @date 2024-04-11
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
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(now - m_start);
    
        return Time(elapsed.count());
    }
}

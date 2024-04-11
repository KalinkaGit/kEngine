/**
 * @file Time.cpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Methods to convert time from a clock
 * @version 1.0.0
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Clock/Clock.hpp"

namespace kEngine
{
    Time::Time(float seconds)
        : m_seconds(seconds)
    {}

    int Time::asSeconds() const
    {
        return static_cast<int>(m_seconds);
    }

    int Time::asMilliseconds() const
    {
        return static_cast<int>(m_seconds * 1000);
    }

    int Time::asMicroseconds() const
    {
        return static_cast<int>(m_seconds * 1000000);
    }
}
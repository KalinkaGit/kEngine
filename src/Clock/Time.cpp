/**
 * @file Convert.cpp
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
/**
 * @file FrameCounter.cpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Little module to count the number of frames per second.
 * @version 1.0.0
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 
#include "Utils/FrameCounter.hpp"

namespace kEngine
{
    FrameCounter::FrameCounter()
        : m_frameCount(0)
        , m_fps(0)
        , m_clock()
    {}

    void FrameCounter::update()
    {
        m_frameCount++;

        if (m_clock.getElapsedTime().asSeconds() >= 1)
        {
            m_fps = m_frameCount;
            m_frameCount = 0;
            m_clock.restart();
        }
    }

    int FrameCounter::getFPS() const
    {
        return m_fps;
    }

    void FrameCounter::printFPS() const
    {
        std::cout << "FPS: " << m_fps << std::endl;
    }
}

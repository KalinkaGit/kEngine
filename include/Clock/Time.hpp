/**
 * @file Time.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-02-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

namespace kEngine
{
    class Time
    {
        public:
            /**
             * @brief Construct a new Time object
             */
            explicit Time(float seconds);

            /**
             * @brief Transform the time to seconds
             */
            int asSeconds() const;

            /**
             * @brief Transform the time to milliseconds
             */
            int asMilliseconds() const;
            
            /**
             * @brief Transform the time to microseconds
             */
            int asMicroseconds() const;

        private:
            float m_seconds;
    };
}

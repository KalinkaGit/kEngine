/**
 * @file Time.hpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Header for conversion of time from a clock
 * @version 1.0.0
 * @date 2024-04-11
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

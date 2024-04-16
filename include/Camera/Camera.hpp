/**
 * @file Camera.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <third-party/glm/glm.hpp>
#include <third-party/glm/gtc/matrix_transform.hpp>

#include "utils/Vectors.hpp"

namespace kEngine
{ 
    enum CameraMovement
    {
            FORWARD,
            BACKWARD,
            LEFT,
            RIGHT
    };

    class Camera
    {
        public:
            Camera(Vec3f position = Vec3f(0.0f, 0.0f, 0.0f), Vec3f up = Vec3f(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f);
            Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

            glm::mat4 getViewMatrix() const;
            void processKeyboard(CameraMovement direction, float deltaTime);
            void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
            void processMouseScroll(float yoffset);
            
            float getZoom() const;
            Vec3f getPosition() const;
            Vec3f getFront() const;
            Vec3f getUp() const;
            float getYaw() const;
            float getPitch() const;
            float getSpeed() const;
            float getSensitivity() const;

        private:
            Vec3f m_position, m_front, m_up;
            float m_yaw, m_pitch, m_speed, m_sensitivity, m_zoom;
            bool m_firstMouse;
            float m_lastX, m_lastY;
    };
}

/**
 * @file Camera.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Camera/Camera.hpp"
#include "utils/Vectors.hpp"

namespace kEngine
{
    Camera::Camera(Vec3f position, Vec3f up, float yaw, float pitch)
        : m_position(position), m_up(up), m_yaw(yaw), m_pitch(pitch), m_speed(2.5f), m_sensitivity(0.1f), m_zoom(45.0f), m_firstMouse(true), m_lastX(800.0f / 2.0), m_lastY(600.0f / 2.0)
    {
        m_front = Vec3f(0.0f, 0.0f, -1.0f);
    }

    Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
        : m_position(Vec3f(posX, posY, posZ)), m_up(Vec3f(upX, upY, upZ)), m_yaw(yaw), m_pitch(pitch), m_speed(2.5f), m_sensitivity(0.1f), m_zoom(45.0f), m_firstMouse(true), m_lastX(800.0f / 2.0), m_lastY(600.0f / 2.0)
    {
        m_front = Vec3f(0.0f, 0.0f, -1.0f);
    }

    glm::mat4 Camera::getViewMatrix() const
    {
        return glm::lookAt(m_position.toGlmVec3(), m_position.toGlmVec3() + m_front.toGlmVec3(), m_up.toGlmVec3());
    }

    void Camera::processKeyboard(CameraMovement direction, float deltaTime)
    {
        float velocity = m_speed * deltaTime;

        switch (direction)
        {
            case FORWARD:
                m_position += m_front * velocity;
                break;
            case BACKWARD:
                m_position -= m_front * velocity;
                break;
            case LEFT:
                m_position -= (m_front.cross(m_up)).normalize() * velocity;
                break;
            case RIGHT:
                m_position += (m_front.cross(m_up)).normalize() * velocity;
                break;
        }
    }

    void Camera::processMouseMovement(float xoffset, float yoffset, bool constrainPitch)
    {
        if (m_firstMouse)
        {
            m_lastX = xoffset;
            m_lastY = yoffset;
            m_firstMouse = false;
        }

        float xpos = xoffset;
        float ypos = yoffset;
        m_lastX = xpos;
        m_lastY = ypos;

        xoffset *= m_sensitivity;
        yoffset *= m_sensitivity;

        m_yaw += xoffset;
        m_pitch += yoffset;

        if (constrainPitch)
        {
            if (m_pitch > 89.0f)
                m_pitch = 89.0f;
            if (m_pitch < -89.0f)
                m_pitch = -89.0f;
        }

        Vec3f front;
        front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        front.y = sin(glm::radians(m_pitch));
        front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
        m_front = front.normalize();
    }

    void Camera::processMouseScroll(float yoffset)
    {
        if (m_zoom >= 1.0f && m_zoom <= 45.0f)
            m_zoom -= yoffset;
        if (m_zoom <= 1.0f)
            m_zoom = 1.0f;
        if (m_zoom >= 45.0f)
            m_zoom = 45.0f;
    }

    float Camera::getZoom() const
    {
        return m_zoom;
    }
}

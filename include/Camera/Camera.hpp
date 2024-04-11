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

#define SPEED 2.5f
#define SENSITIVITY 0.1f
#define ZOOM 45.0f

#include <third-party/glm/glm.hpp>
#include <third-party/glm/gtc/matrix_transform.hpp>

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


            glm::vec3 Position;
            glm::vec3 Front;
            glm::vec3 Up;
            glm::vec3 Right;
            glm::vec3 WorldUp;

            float Yaw;
            float Pitch;

            float MovementSpeed;
            float MouseSensitivity;
            float Zoom;

            Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.0f, float pitch = 0.0f);

            glm::mat4 GetViewMatrix();

            void ProcessKeyboard(CameraMovement direction, float deltaTime);
            void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
            void ProcessMouseScroll(float yoffset);

        private:
            void updateCameraVectors();
    };
}

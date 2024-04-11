#include <iostream>
#include <windows.h>
#include <unistd.h>

#include "Window/Window.hpp"
#include "Utils/FrameCounter.hpp"
#include "Camera/Camera.hpp"
#include "Shader/Shader.hpp"

void manageKeyboardInput(kEngine::Window &window, kEngine::Camera &camera)
{
    if (window.isKeyPressed(GLFW_KEY_W))
    {
        camera.ProcessKeyboard(kEngine::FORWARD, 0.1f);
    }
    if (window.isKeyPressed(GLFW_KEY_S))
    {
        camera.ProcessKeyboard(kEngine::BACKWARD, 0.1f);
    }
    if (window.isKeyPressed(GLFW_KEY_A))
    {
        camera.ProcessKeyboard(kEngine::LEFT, 0.1f);
    }
    if (window.isKeyPressed(GLFW_KEY_D))
    {
        camera.ProcessKeyboard(kEngine::RIGHT, 0.1f);
    }
}

int main(void)
{
    kEngine::Window window("kEngine", kEngine::State::Windowed, 1200, 600);

    kEngine::FrameCounter frameCounter;
    kEngine::Camera camera;
    kEngine::Shader shader("shaders/test.vs.glsl", "shaders/test.fs.glsl");
    // Vertices du cube
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,

        // Ajoutez les autres faces ici
    };

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    while (!window.shouldClose())
    {
        window.display();

        frameCounter.update();

        //std::cout << frameCounter.getFPS() << std::endl;
        // Créez et appliquez vos transformations ici
        glm::mat4 model = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime(), glm::vec3(1.0f, 0.3f, 0.5f));
        
        shader.setUniformMat4f("model", model);
        shader.setUniformMat4f("view", camera.GetViewMatrix());
        shader.setUniformMat4f("projection", glm::perspective(glm::radians(camera.Zoom), 1200.0f / 600.0f, 0.1f, 100.0f));
        shader.bind();

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        // get keyboard input
        manageKeyboardInput(window, camera);

        std::cout << camera.Position.x << " " << camera.Position.y << " " << camera.Position.z << std::endl;

        window.clear();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    window.terminate();
    
    return 0;
}

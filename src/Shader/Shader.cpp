/**
 * @file Shader.cpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Methods to manage shaders
 * @version 1.0.0
 * @date 2024-04-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Shader/Shader.hpp"

namespace kEngine
{
    Shader::Shader(const std::string &vertexShaderPath,
                   const std::string &fragmentShaderPath)
        : m_rendererID(0)
    {
        std::string vertexShaderSource = parseShader(vertexShaderPath);
        std::string fragmentShaderSource = parseShader(fragmentShaderPath);

        m_rendererID = createShader(vertexShaderSource, fragmentShaderSource);
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_rendererID);
    }

    void Shader::bind() const
    {
        glUseProgram(m_rendererID);
    }

    void Shader::unbind() const
    {
        glUseProgram(0);
    }

    unsigned int Shader::compileShader(unsigned int type, const std::string &source)
    {
        unsigned int id = glCreateShader(type); // Create a shader object
        const char *src = source.c_str();      // Get the source code

        glShaderSource(id, 1, &src, nullptr); // Attach the source code to the shader object
        glCompileShader(id);                 // Compile the shader

        int result;
        
        glGetShaderiv(id, GL_COMPILE_STATUS, &result); // Get the compile status
        
        if (result == GL_FALSE) // Error handling
        {
            int length;
        
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

            char *message = (char *)alloca(length * sizeof(char));

            glGetShaderInfoLog(id, length, &length, message);
            std::cout << "Failed to compile "
                      << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
                      << " shader!" << std::endl;
            std::cout << message << std::endl;

            glDeleteShader(id);

            return (0);
        }

        return (id);
    }

    unsigned int Shader::createShader(const std::string &vertexShader,
                                      const std::string &fragmentShader)
    {
        unsigned int program = glCreateProgram(); // Create a program object
        unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader); // Compile the vertex shader
        unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader); // Compile the fragment shader

        glAttachShader(program, vs); // Attach the vertex shader to the program
        glAttachShader(program, fs); // Attach the fragment shader to the program
        glLinkProgram(program); // Link the program
        glValidateProgram(program); // Validate the program

        int result;

        glGetProgramiv(program, GL_LINK_STATUS, &result); // Get the link status

        if (result == GL_FALSE) // Error handling
        {
            int length;

            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);

            char *message = (char *)alloca(length * sizeof(char));

            glGetProgramInfoLog(program, length, &length, message);
            std::cout << "Failed to link shader program!" << std::endl;
            std::cout << message << std::endl;

            glDeleteProgram(program);
            glDeleteShader(vs);
            glDeleteShader(fs);

            return (0);
        }

        glDeleteShader(vs);
        glDeleteShader(fs);

        return (program);
    }

    std::string Shader::parseShader(const std::string &filepath)
    {
        std::ifstream stream(filepath); // Open the file
        std::string line; // Store the line
        std::stringstream ss; // Store the source code

        while (getline(stream, line)) // Read the file
        {
            ss << line << '\n'; // Append the line to the source code
        }

        return (ss.str()); // Return the source code
    }
}

/**
 * @file Uniform.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Shader/Shader.hpp"

namespace kEngine
{
    int Shader::getUniformLocation(const std::string &name)
    {
        if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end())
        {
            return m_uniformLocationCache[name];
        }

        int location = glGetUniformLocation(m_rendererID, name.c_str());
        if (location == -1)
        {
            std::cout << "Warning: uniform '" << name << "' doesn't exist!" << std::endl;
        }

        m_uniformLocationCache[name] = location;
    
        return (location);
    }

    void Shader::setUniform1i(const std::string &name, int value)
    {
        glUniform1i(getUniformLocation(name), value);
    }

    void Shader::setUniform1f(const std::string &name, float value)
    {
        glUniform1f(getUniformLocation(name), value);
    }

    void shader::setUniform4f(
        const std::string &name,
        float v0,
        float v1,
        float v2,
        float v3
    )
    {
        glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
    }

    void Shader::setUniformMat4f(const std::string &name, const glm::mat4 &matrix)
    {
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
    }
}

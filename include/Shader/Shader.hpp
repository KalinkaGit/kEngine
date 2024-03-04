/**
 * @file Shader.hpp
 * @author 
 * @brief Shaders are programs that run on the GPU. They are used to compute rendering effects and are written in GLSL.
 * @version 0.1
 * @date 2024-03-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

namespace kEngine
{
    class Shader
    {
        public:
            /**
             * @brief Construct a new Shader object
             * 
             * @param vertexShaderPath Path to the vertex shader
             * @param fragmentShaderPath Path to the fragment shader
             */
            Shader(const std::string &vertexShaderPath,
                   const std::string &fragmentShaderPath);
            ~Shader();

            /**
             * @brief Bind the shader
             */
            void bind() const;

            /**
             * @brief Unbind the shader
             */
            void unbind() const;

            /**
             * @brief Set the Uniform1i object
             * 
             * @param name Name of the uniform
             * @param value Value to be set
             */
            void setUniform1i(const std::string &name, int value);
            
            /**
             * @brief Set the Uniform1f object
             * 
             * @param name Name of the uniform
             * @param value Value to be set
             */
            void setUniform1f(const std::string &name, float value);

            /**
             * @brief Set the Uniform4f object
             * 
             * @param name Name of the uniform
             * @param v0 Value 0
             * @param v1 Value 1
             * @param v2 Value 2
             * @param v3 Value 3
             */
            void setUniform4f(const std::string &name, float v0, float v1, float v2, float v3);

            /**
             * @brief Set the Uniform Mat4f object
             * 
             * @param name Name of the uniform
             * @param matrix Matrix to be set
             */
            void setUniformMat4f(const std::string &name, const glm::mat4 &matrix);

        private:
            unsigned int m_rendererID;
            std::unordered_map<std::string, int> m_uniformLocationCache;

            /**
             * @brief Get the Uniform Location object
             * 
             * @param name Name of the uniform
             * @return int Location of the uniform
             */
            int getUniformLocation(const std::string &name);
            
            /**
             * @brief Compile the shader
             * 
             * @param type Type of the shader
             * @param source Source code of the shader
             * @return unsigned int Shader ID
             */
            unsigned int compileShader(unsigned int type,
                                       const std::string &source);

            /**
             * @brief Create a Shader object
             * 
             * @param vertexShader Vertex shader path
             * @param fragmentShader Fragment shader path
             * @return unsigned int Shader ID
             */
            unsigned int createShader(const std::string &vertexShader,
                                      const std::string &fragmentShader);
                                    
            /**
             * @brief Parse the shader file
             *
             * @param filepath Path to the shader file
             * @return std::string Source code of the shader
             */
            std::string parseShader(const std::string &filepath);
    };
}

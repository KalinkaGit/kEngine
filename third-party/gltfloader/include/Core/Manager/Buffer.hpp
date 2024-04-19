/**
 * @file Buffer.hpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Header file of the Buffer Manager class
 * @version 1.0.0
 * @date 2024-04-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../Reader/Reader.hpp"

namespace GLTFLoader
{
    class BufferManager
    {
        public:
            /**
             * @brief Construct a new Buffer Manager object
             * 
             */
            BufferManager();

            /**
             * @brief Load the buffers from a GLTF file
             * 
             * @param jsonContent Content of the GLTF file
             * @return int 0 if the loading was successful, -1 otherwise
             */
            int loadBuffersFromGLTF(const std::string &jsonContent);

            /**
             * @brief Get the buffer data
             * 
             * @param index Index of the buffer
             * @return const std::vector<unsigned char>& Vector of bytes
             */
            const std::vector<unsigned char> &getBufferData(int index) const;
    
        private:
            std::vector<std::vector<unsigned char>> m_buffers;

            /**
             * @brief Load a buffer from a GLTF file
             * 
             * @param uri URI of the buffer
             * @return int 0 if the loading was successful, -1 otherwise
             */
            int loadBuffer(const std::string &uri);
    };
}
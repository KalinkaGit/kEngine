/**
 * @file Reader.hpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Header file of the Reader class
 * @version 1.0.0
 * @date 2024-04-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

namespace GLTFLoader
{
    class Reader
    {
        public:
            /**
             * @brief Construct a new Reader object
             * 
             * @param path Path to the file to read
             */
            explicit Reader(const std::string &path);

            /**
             * @brief set the file path
             *
             * @param path Path to the file to read
             */
            void setFilePath(const std::string &path);

            /**
             * @brief Read a text file
             * 
             * @return std::string Content of the file
             */
            std::string readTextFile() const;

            /**
             * @brief Read a binary file
             * 
             * @return std::vector<unsigned char> Vector of bytes
             */
            std::vector<unsigned char> readBinaryFile() const;

        private:
            std::string m_path;
    };
}

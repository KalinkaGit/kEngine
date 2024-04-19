/**
 * @file Loader.hpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Header file of the Loader class
 * @version 1.0.0
 * @date 2024-04-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include "../../nlohmann/json.hpp"
#include "../Types.hpp"

namespace GLTFLoader
{
    class Loader
    {
        public:
            /**
             * @brief Construct a new Loader object
             * 
             * @param path Path to the file to load
             */
            explicit Loader(const std::string &path);

            /**
             * @brief Load the file
             * 
             * @return int 0 if the loading was successful, -1 otherwise
             */
            int load(void);

            /**
             * @brief Get the Scene object
             * 
             * @return Scene 
             */
            Scene getScene(void) const;

        private:
            std::string m_path;
            Scene m_scene;
            nlohmann::json m_json;
            std::vector<std::vector<unsigned char>> m_buffers;

            /**
             * @brief Load binary data from a file
             * 
             * @param uri URI of the file to load
             * @return std::vector<unsigned char> Vector of bytes
             */
            std::vector<unsigned char> loadBinaryData(const std::string &uri);

            /**
             * @brief Extract the vertices from an accessor
             * 
             * @param accessorIndex Index of the accessor
             * @return std::vector<Vertex> Vector of vertices
             */
            std::vector<GLTFLoader::Vertex> extractVertices(int accessorIndex);

            /**
             * @brief Extract the indices from an accessor
             * 
             * @param accessorIndex Index of the accessor
             * @return std::vector<unsigned int> Vector of indices
             */
            std::vector<unsigned int> extractIndices(int accessorIndex);
            
            /**
             * @brief Resolve the accessor from index
             * 
             * @param accessorIndex Index of the accessor
             * @return std::vector<unsigned char> Vector of bytes
             */
            std::vector<unsigned char> resolveAccessor(int accessorIndex);

            /**
             * @brief Extract the texture coordinates from an accessor
             * 
             * @param accessorIndex Index of the accessor
             * @return std::vector<v2f> Vector of texture coordinates
             */
            std::vector<float> extractAnimationTimes(int accessorIndex);

            /**
             * @brief Extract the translation keys from an accessor
             * 
             * @param accessorIndex Index of the accessor
             * @return std::vector<v3f> Vector of translation keys
             */
            std::vector<v3f> extractTranslationKeys(int accessorIndex);

            /**
             * @brief Extract the rotation keys from an accessor
             * 
             * @param accessorIndex Index of the accessor
             * @return std::vector<v4f> Vector of rotation keys
             */
            std::vector<v4f> extractRotationKeys(int accessorIndex);

            /**
             * @brief Extract the scale keys from an accessor
             * 
             * @param accessorIndex Index of the accessor
             * @return std::vector<v3f> Vector of scale keys
             */
            std::vector<v3f> extractScaleKeys(int accessorIndex);

            /**
             * @brief Parse the JSON file
             *
             * @return int 0 if the parsing was successful, -1 otherwise
             */
            int parseJSON(const nlohmann::json &json);

            /**
             * @brief Load the buffers
             * 
             * @return int 0 if the loading was successful, -1 otherwise
             */
            int loadBuffers(void);

            /**
             * @brief Load the meshes
             * 
             * @return int 0 if the loading was successful, -1 otherwise
             */
            int loadMeshes(void);

            /**
             * @brief Load the materials
             * 
             * @return int 0 if the loading was successful, -1 otherwise
             */
            int loadMaterials(void);

            /**
             * @brief Load the texture
             * 
             * @param textureIndex Index of the texture to load
             * @return std::string Path to the loaded texture
             */
            std::string loadTexture(int textureIndex);

            /**
             * @brief Load the nodes
             * 
             * @return int 0 if the loading was successful, -1 otherwise
             */
            int loadNodes(void);

            /**
             * @brief Load the animations
             * 
             * @return int 0 if the loading was successful, -1 otherwise
             */
            int loadAnimations(void);
    };
}
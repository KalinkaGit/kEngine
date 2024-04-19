/**
 * @file Scene.hpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Header file of the Scene class
 * @version 1.0.0
 * @date 2024-04-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

#include "../Types.hpp"
#include "Buffer.hpp"
#include "../../nlohmann/json.hpp"

namespace GLTFLoader
{
    class SceneManager
    {
        public:
            /**
             * @brief Construct a new Scene Manager object
             * 
             * @param bufferManager Buffer Manager object
             */
            explicit SceneManager(BufferManager &bufferManager);

            /**
             * @brief Build the scene from a JSON file
             * 
             * @param jsonContent Content of the JSON file
             * @return int 0 if the building was successful, -1 otherwise
             */
            int buildSceneFromJSON(const std::string &jsonContent);

            /**
             * @brief Get the scene
             * 
             * @return Scene Scene object
             */
            const Scene &getScene(void) const;

        private:
            Scene m_scene;
            nlohmann::json m_json;
            BufferManager &m_bufferManager;
            std::unordered_map<int, std::shared_ptr<Node>> m_nodeMap;

            /**
             * @brief Process the nodes
             * 
             * @param nodesJson JSON object of the nodes
             */
            void processNodes(const nlohmann::json &nodesJson);

            /**
             * @brief Process the meshes
             * 
             * @param meshesJson JSON object of the meshes
             */
            void processMeshes(const nlohmann::json &meshesJson);

            /**
             * @brief Process the materials
             * 
             * @param materialsJson JSON object of the materials
             */
            void processMaterials(const nlohmann::json &materialsJson);

            /**
             * @brief Load the vertex positions
             * 
             * @param accessorIndex Index of the accessor
             * @return std::vector<v3f> Vector of 3D vectors
             */
            std::vector<Vertex> loadVertexPositions(int accessorIndex);

            /**
             * @brief Load the indices
             *
             * @param accessorIndex Index of the accessor
             * @return std::vector<unsigned int> Vector of indices
             */
            std::vector<unsigned int> loadIndices(int accessorIndex);

            /**
             * @brief Load the texture
             *
             * @param textureIndex Index of the texture
             * @return std::string Path to the texture
             */
            std::string loadTexture(int textureIndex);
    };
}
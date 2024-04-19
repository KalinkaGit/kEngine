/**
 * @file Types.hpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Header file defining the types used for GLTF Loader
 * @version 1.0.0
 * @date 2024-04-18
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <vector>
#include <string>
#include <memory>

namespace GLTFLoader
{
    /*----------------------------------------------
    ---------------------BASICS---------------------
    ----------------------------------------------*/

    /**
     * @brief Structure representing a 2D vector of floats
     * 
     */
    struct v2f
    {
        float x, y;
    };

    /**
     * @brief Structure representing a 3D vector of floats
     * 
     */
    struct v3f
    {
        float x, y, z;
    };

    /**
     * @brief Structure representing a 4D vector of floats
     * 
     */
    struct v4f
    {
        float x, y, z, w;
    };

    /**
     * @brief Structure representing a 4x4 matrix of floats
     * 
     */
    struct m4f
    {
        float data[16];
    };

    /*----------------------------------------------
    ----------------------MESHES--------------------
    ----------------------------------------------*/

    /**
     * @brief Structure a vertex of a mesh
     * 
     */
    struct Vertex
    {
        v3f position;
        v3f normal;
        v2f texCoords;
    };

    /**
     * @brief Structure representing a mesh
     *
     */
    struct Mesh
    {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        int materialIndex;
    };

    /*----------------------------------------------
    ---------------------MATERIALS------------------
    ----------------------------------------------*/

    /**
     * @brief Structure representing a material
     *
     */
    struct Material
    {
        v4f baseColorFactor;
        float metallicFactor;
        float roughnessFactor;
        std::string albedoTexture;
        std::string normalTexture;
        std::string metallicRoughnessTexture;
    };

    /*----------------------------------------------
    --------------------ANIMATIONS------------------
    ----------------------------------------------*/

    /**
     * @brief Structure representing an animation key
     *
     */
    struct AnimationKey
    {
        float time;
        v3f translation;
        v4f rotation;
        v3f scale;
    };

    /**
     * @brief Structure representing an animation channel
     *
     */
    struct AnimationChannel
    {
        std::string targetNode;
        std::vector<AnimationKey> keys;
    };

    /**
     * @brief Structure representing an animation
     *
     */
    struct Animation
    {
        std::string name;
        std::vector<AnimationChannel> channels;
    };

    /*----------------------------------------------
    ----------------------SCENE---------------------
    ----------------------------------------------*/

    /**
     * @brief Structure representing a node of a scene
     *
     */
    struct Node
    {
        std::string name;
        std::vector<std::shared_ptr<Node>> children;
        std::shared_ptr<Mesh> mesh;
        v4f rotation;
        v3f scale;
        v3f translation;
        m4f transform;
        int meshIndex;
    };

    /**
     * @brief Structure representing a scene
     *
     */
    struct Scene
    {
        std::vector<std::shared_ptr<Node>> nodes;
        std::vector<Material> materials;
        std::vector<Mesh> meshes;
        std::vector<Animation> animations;
    };
}

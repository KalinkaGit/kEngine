/**
 * @file Vectors.hpp
 * @author Kalinka (KalinkaGit) (remi.grimault@gmail.com)
 * @brief Header of the Vectors class
 * @version 1.0.0
 * @date 2024-04-16
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once

#include <third-party/glm/glm.hpp>
#include <cmath>

namespace kEngine
{
    template<typename T>
    class Vec2
    {
        public:
            T x, y;

            /**
             * @brief Construct a new Vec2 object
             */
            Vec2()
                : x(0)
                , y(0)
            {}

            /**
             * @brief Construct a new Vec2 object
             * 
             * @param x X coordinate
             * @param y Y coordinate
             */
            Vec2(T x, T y)
                : x(x)
                , y(y)
            {}

            /**
             * @brief Destroy the Vec2 object
             */
            ~Vec2() = default;

            // Vector addition
            /**
             * @brief Operator + overload
             * 
             * @param v Vector to add
             * @return Vec2 Result of the addition
             */
            Vec2 operator+(const Vec2& v) const { return Vec2(x + v.x, y + v.y); }
            
            /**
             * @brief Operator += overload
             * 
             * @param v Vector to add
             * @return Vec2& Result of the addition
             */
            Vec2& operator+=(const Vec2& v) { x += v.x; y += v.y; return *this; }

            // Vector subtraction
            /**
             * @brief Operator - overload
             * 
             * @param v Vector to subtract
             * @return Vec2 Result of the subtraction
             */
            Vec2 operator-(const Vec2& v) const { return Vec2(x - v.x, y - v.y); }
            
            /**
             * @brief Operator -= overload
             * 
             * @param v Vector to subtract
             * @return Vec2& Result of the subtraction
             */
            Vec2& operator-=(const Vec2& v) { x -= v.x; y -= v.y; return *this; }

            // Scalar multiplication
            /**
             * @brief Operator * overload
             * 
             * @param s Scalar to multiply
             * @return Vec2 Result of the multiplication
             */
            Vec2 operator*(T s) const { return Vec2(x * s, y * s); }
            
            /**
             * @brief Operator *= overload
             * 
             * @param s Scalar to multiply
             * @return Vec2& Result of the multiplication
             */
            Vec2& operator*=(T s) { x *= s; y *= s; return *this; }

            // Scalar division
            /**
             * @brief Operator / overload
             * 
             * @param s Scalar to divide
             * @return Vec2 Result of the division
             */
            Vec2 operator/(T s) const { return Vec2(x / s, y / s); }

            /**
             * @brief Operator /= overload
             * 
             * @param s Scalar to divide
             * @return Vec2& Result of the division
             */
            Vec2& operator/=(T s) { x /= s; y /= s; return *this; }

            // Normalize the vector
            /**
             * @brief Normalize the vector
             * 
             * @return Vec2& Normalized vector
             */
            Vec2& normalize()
            {
                T length = std::sqrt(x * x + y * y);
                x /= length;
                y /= length;
                return *this;
            }

            // Dot product
            /**
             * @brief Dot product
             * 
             * @param v Vector to calculate the dot product with
             * @return T Result of the dot product
             */
            T dot(const Vec2& v) const { return x * v.x + y * v.y; }

            // Cross product
            /**
             * @brief Cross product
             * 
             * @param v Vector to calculate the cross product with
             * @return Vec2 Result of the cross product
             */
            Vec2 cross(const Vec2& v) const { return Vec2(x * v.y - y * v.x); }
    };

    template<typename T>
    class Vec3
    {
        public:
            T x, y, z;

            /**
             * @brief Construct a new Vec3 object
             */
            Vec3()
                : x(0)
                , y(0)
                , z(0)
            {}

            /**
             * @brief Construct a new Vec3 object
             * 
             * @param x X coordinate
             * @param y Y coordinate
             * @param z Z coordinate
             */
            Vec3(T x, T y, T z)
                : x(x)
                , y(y)
                , z(z)
            {}

            /**
             * @brief Destroy the Vec3 object
             */
            ~Vec3() = default;

            // Vector addition
            /**
             * @brief Operator + overload
             * 
             * @param v Vector to add
             * @return Vec3 Result of the addition
             */
            Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
            
            /**
             * @brief Operator += overload
             * 
             * @param v Vector to add
             * @return Vec3& Result of the addition
             */
            Vec3& operator+=(const Vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }

            // Vector subtraction
            /**
             * @brief Operator - overload
             * 
             * @param v Vector to subtract
             * @return Vec3 Result of the subtraction
             */
            Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
            
            /**
             * @brief Operator -= overload
             * 
             * @param v Vector to subtract
             * @return Vec3& Result of the subtraction
             */
            Vec3& operator-=(const Vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }

            // Scalar multiplication
            /**
             * @brief Operator * overload
             * 
             * @param s Scalar to multiply
             * @return Vec3 Result of the multiplication
             */
            Vec3 operator*(T s) const { return Vec3(x * s, y * s, z * s); }

            /**
             * @brief Operator *= overload
             * 
             * @param s Scalar to multiply
             * @return Vec3& Result of the multiplication
             */
            Vec3& operator*=(T s) { x *= s; y *= s; z *= s; return *this; }

            // Scalar division
            /**
             * @brief Operator / overload
             * 
             * @param s Scalar to divide
             * @return Vec3 Result of the division
             */
            Vec3 operator/(T s) const { return Vec3(x / s, y / s, z / s); }

            /**
             * @brief Operator /= overload
             * 
             * @param s Scalar to divide
             * @return Vec3& Result of the division
             */
            Vec3& operator/=(T s) { x /= s; y /= s; z /= s; return *this; }

            // Normalize the vector
            /**
             * @brief Normalize the vector
             * 
             * @return Vec3& Normalized vector
             */
            Vec3& normalize()
            {
                T length = std::sqrt(x * x + y * y + z * z);
                x /= length;
                y /= length;
                z /= length;
                return *this;
            }

            // Dot product
            /**
             * @brief Dot product
             * 
             * @param v Vector to calculate the dot product with
             * @return T Result of the dot product
             */
            T dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }

            // Cross product
            /**
             * @brief Cross product
             * 
             * @param v Vector to calculate the cross product with
             * @return Vec3 Result of the cross product
             */
            Vec3 cross(const Vec3& v) const { return Vec3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x); }
    
            glm::vec3 toGlmVec3() const { return glm::vec3(x, y, z); }
    };

    template<typename T>
    class Vec4
    {
        public:
            T x, y, z, w;

            /**
             * @brief Construct a new Vec4 object
             */
            Vec4()
                : x(0)
                , y(0)
                , z(0)
                , w(0)
            {}

            /**
             * @brief Construct a new Vec4 object
             * 
             * @param x X coordinate
             * @param y Y coordinate
             * @param z Z coordinate
             * @param w W coordinate
             */
            Vec4(T x, T y, T z, T w)
                : x(x)
                , y(y)
                , z(z)
                , w(w)
            {}

            /**
             * @brief Destroy the Vec4 object
             */
            ~Vec4() = default;

            // Vector addition
            /**
             * @brief Operator + overload
             * 
             * @param v Vector to add
             * @return Vec4 Result of the addition
             */
            Vec4 operator+(const Vec4& v) const { return Vec4(x + v.x, y + v.y, z + v.z, w + v.w); }
            
            /**
             * @brief Operator += overload
             * 
             * @param v Vector to add
             * @return Vec4& Result of the addition
             */
            Vec4& operator+=(const Vec4& v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; }

            // Vector subtraction
            /**
             * @brief Operator - overload
             * 
             * @param v Vector to subtract
             * @return Vec4 Result of the subtraction
             */
            Vec4 operator-(const Vec4& v) const { return Vec4(x - v.x, y - v.y, z - v.z, w - v.w); }
            
            /**
             * @brief Operator -= overload
             * 
             * @param v Vector to subtract
             * @return Vec4& Result of the subtraction
             */
            Vec4& operator-=(const Vec4& v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; }

            // Scalar multiplication
            /**
             * @brief Operator * overload
             * 
             * @param s Scalar to multiply
             * @return Vec4 Result of the multiplication
             */
            Vec4 operator*(T s) const { return Vec4(x * s, y * s, z * s, w * s); }

            /**
             * @brief Operator *= overload
             * 
             * @param s Scalar to multiply
             * @return Vec4& Result of the multiplication
             */
            Vec4& operator*=(T s) { x *= s; y *= s; z *= s; w *= s; return *this; }

            // Scalar division
            /**
             * @brief Operator / overload
             * 
             * @param s Scalar to divide
             * @return Vec4 Result of the division
             */
            Vec4 operator/(T s) const { return Vec4(x / s, y / s, z / s, w / s); }

            /**
             * @brief Operator /= overload
             * 
             * @param s Scalar to divide
             * @return Vec4& Result of the division
             */
            Vec4& operator/=(T s) { x /= s; y /= s; z /= s; w /= s; return *this; }
    
            // Normalize the vector
            /**
             * @brief Normalize the vector
             * 
             * @return Vec4& Normalized vector
             */
            Vec4& normalize()
            {
                T length = std::sqrt(x * x + y * y + z * z + w * w);
                x /= length;
                y /= length;
                z /= length;
                w /= length;
                return *this;
            }

            // Dot product
            /**
             * @brief Dot product
             * 
             * @param v Vector to calculate the dot product with
             * @return T Result of the dot product
             */
            T dot(const Vec4& v) const { return x * v.x + y * v.y + z * v.z + w * v.w; }

            // Cross product
            /**
             * @brief Cross product
             * 
             * @param v Vector to calculate the cross product with
             * @return Vec4 Result of the cross product
             */
            Vec4 cross(const Vec4& v) const { return Vec4(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x, 0); }
    };

    // common types
    typedef Vec2<int> Vec2i;
    typedef Vec2<float> Vec2f;
    typedef Vec2<unsigned int> Vec2u;

    typedef Vec3<int> Vec3i;
    typedef Vec3<float> Vec3f;
    typedef Vec3<unsigned int> Vec3u;

    typedef Vec4<int> Vec4i;
    typedef Vec4<float> Vec4f;
    typedef Vec4<unsigned int> Vec4u;
}

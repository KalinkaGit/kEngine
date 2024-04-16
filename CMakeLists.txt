cmake_minimum_required(VERSION 3.12.0)
project(kEngine VERSION 1.0.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
    "third-party/glad/src/glad.c"
)

add_executable(kEngine ${SOURCES})

find_package(OpenGL REQUIRED)

include_directories("include")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory("third-party/glfw")

set(GLM_DIR "third-party/glm")

add_subdirectory("third-party/glm")

include_directories(glad "third-party/glad/include")

include_directories(stbi "third-party/other/stb")

target_include_directories(kEngine PRIVATE ${OPENGL_INCLUDE_DIR})

target_link_libraries(kEngine PRIVATE glfw)

target_link_libraries(kEngine PRIVATE glm)

target_link_libraries(kEngine PRIVATE ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

cmake_minimum_required(VERSION 3.29.0-rc1)
project(kEngine VERSION 1.0.0 LANGUAGES CXX)

include(CTest)
enable_testing()

file(GLOB_RECURSE SOURCES 
    "src/*.cpp"
)

add_executable(kEngine ${SOURCES})

find_package(OpenGL REQUIRED)

include_directories("include")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory("glfw")

set(GLM_DIR "glm")

add_subdirectory("glm")

target_include_directories(kEngine PRIVATE ${OPENGL_INCLUDE_DIR})

target_link_libraries(kEngine PRIVATE glfw)

target_link_libraries(kEngine PRIVATE glm)

target_link_libraries(kEngine PRIVATE ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

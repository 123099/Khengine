cmake_minimum_required(VERSION 3.17)
project(Khengine)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME})

find_package(OpenGL REQUIRED)

# includes
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC externals/glfw/include)

# sources
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(externals/glfw)

add_subdirectory(src)

# libraries
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)

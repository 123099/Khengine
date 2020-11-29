cmake_minimum_required(VERSION 3.17)
project(Khengine)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME})

# includes
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC externals/glfw/include)

# sources
add_subdirectory(externals/glfw)
add_subdirectory(src)

# libraries
target_link_libraries(${PROJECT_NAME} glfw ${GLFW_LIBRARIES})
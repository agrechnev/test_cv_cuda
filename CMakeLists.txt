cmake_minimum_required(VERSION 3.1)
project(test_cv_cuda)
set(CMAKE_CXX_STANDARD 14)

file(COPY lena512.png DESTINATION .)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBRARIES})

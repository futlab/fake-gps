cmake_minimum_required(VERSION 3.5.1)

project(fake-gps)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(libmavconn REQUIRED)
find_package(Boost)

include_directories(${libmavconn_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} "main.cpp")

target_link_libraries(${PROJECT_NAME}
    ${Boost_LIBRARIES}
    ${libmavconn_LIBRARIES}
)

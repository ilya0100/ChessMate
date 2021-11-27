CMAKE_MINIMUM_REQUIRED(VERSION 3.13.4)
PROJECT(ChessMate)

SET(CMAKE_CXX_STANDART 17)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -lsml-graphics -lsfml-window -lsfml-system")

add_executable(${PROJECT_NAME} project/src/main.cpp)

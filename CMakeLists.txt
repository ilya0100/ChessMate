CMAKE_MINIMUM_REQUIRED(VERSION 3.13.4)
PROJECT(ChessMate.out)

SET(CMAKE_CXX_STANDART 17)

INCLUDE_DIRECTORIES(project/include)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(${PROJECT_NAME} project/src/logic.cpp project/src/main.cpp project/src/textures.cpp project/src/utils.cpp)

target_link_libraries(ChessMate.out sfml-graphics sfml-audio)

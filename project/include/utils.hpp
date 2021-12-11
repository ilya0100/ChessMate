#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <sys/socket.h>

// figures
#define SPRITE_SIZE 264
#define CELL_SIZE (264 * SCALE_FACTOR)

// scale
#define SCALE_FACTOR 0.2

typedef struct {
    int x;
    int y;
} NumCage;

typedef enum {
    B_ROOK,     // 0
    B_KNIGHT,   // 1
    B_BISHOP,   // 2
    B_QUEEN,    // 3
    B_KING,     // 4
    B_PAWN,     // 5
    EMPTY_CELL, // 12
    W_ROOK,     // 6
    W_KNIGHT,   // 7
    W_BISHOP,   // 8
    W_QUEEN,    // 9
    W_KING,     // 10
    W_PAWN      // 11
} figureName;

typedef enum {
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H
} Letter_Position;

typedef enum {
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT
} Digit_Position;

typedef enum {
    WHITE,
    BLACK
} Figure_Side;

class ReuseableListener : public sf::TcpListener {
public:
        void reuse() {
                char reuse = 1;
                setsockopt(getHandle(), SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
        }
};

class Window {

    protected:
        sf::RenderWindow *window;
        sf::Vector2u windowSize;
        sf::Vector2u windowSizeNew;
        sf::Vector2f windowRatio;

    public:
        Window(sf::VideoMode Mode, std::string s);
        sf::RenderWindow* getWindow();
        sf::Vector2u getWindowSize();
        sf::Vector2u getWindowSizeNew();
        sf::Vector2f getWindowRatio();

};




void menu(sf::RenderWindow & window);
sf::Vector2u getCurrCage(sf::Vector2i pos, sf::Vector2i playSpace);

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>

// figures
#define SPRITE_SIZE 264
#define CELL_SIZE (264 * SCALE_FACTOR)

// scale
#define SCALE_FACTOR 0.2

// board parameters
#define X_BOARD_SIZE 2400
#define Y_BOARD_SIZE 2400
#define X_PLAYSPACE (144 * SCALE_FACTOR)    //  960
#define Y_PLAYSPACE (144 * SCALE_FACTOR)    //  624

// window
#define X_SCALE_W 2
#define Y_SCALE_W 1.3
#define X_WINDOW (X_BOARD_SIZE * X_SCALE_W * SCALE_FACTOR)
#define Y_WINDOW (Y_BOARD_SIZE * Y_SCALE_W * SCALE_FACTOR)

// buttons parameters
#define X_EXIT 149
#define Y_EXIT 53
#define X_BACK 284
#define Y_BACK 53

// scale
// #define SCALE_FACTOR 0.2

#define TSPRITE_SIZE (SPRITE_SIZE * SCALE_FACTOR)

typedef struct settings{
    static float scale_factor;
    static float cell_size;
    static float sprite_size;
    static float x_board_size;
    static float y_board_size;
    static float x_playspace;
    static float y_playspace;
    static float x_scale_w;
    static float y_scale_w;
    static float x_window;
    static float y_window;
    static float tsprite_size;

    static float getSf() {return scale_factor;};
    static float getSs() {return 264;};
    static float getCs() {return scale_factor * 264;};
    static float getXbs() {return 2400;};
    static float getYbs() {return 2400;};
    static float getXw() {x_window = x_board_size * x_scale_w * scale_factor; return x_window;};
    static float getYw() {y_window = y_board_size * y_scale_w * scale_factor; return y_window;};
    static float getTSs() { return 264 * scale_factor;};

    static float getPsX() {return scale_factor * 144;};
    static float getPsY() {return scale_factor * 144;};

} settings;

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
} PlaySide;

typedef enum {
    ONE_PLAYER,
    HOST,
    CLIENT
} GameMode;

class ReuseableListener : public sf::TcpListener {
public:
    void reuse() {
        char reuse = 1;
        setsockopt(getHandle(), SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    }
};

class Window: public sf::RenderWindow {

    protected:
        sf::Vector2u Size;
        sf::Vector2u SizeNew;
        sf::Vector2f Ratio;

    public:
        Window(sf::VideoMode mode, const sf::String &title): sf::RenderWindow(mode, title) {Size = getSize(); SizeNew = getSize();};
        sf::Vector2u getSizeNew();
        sf::Vector2f getRatio();

};


sf::Vector2u getCurrCage(sf::Vector2i pos /*sf::Vector2i playSpace*/);

// static Flags flags;

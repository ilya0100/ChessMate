#pragma once

#include <SFML/Graphics.hpp>
#include <string>

// window
#define X_WINDOW 900
#define Y_WINDOW 750

// figures
#define SPRITE_SIZE 264

// board parameters
#define X_BOARD_SIZE 2400
#define Y_BOARD_SIZE 2400
#define X_PLAYSPACE 144
#define Y_PLAYSPACE 144
#define CELL_SIZE (264 * SCALE_FACTOR)

// scale
#define SCALE_FACTOR 0.25

typedef struct {
    int x;
    int y;
} NumCage;

typedef enum {
    B_ROOK,
    B_KNIGHT,
    B_BISHOP,
    B_QUEEN,
    B_KING,
    B_PAWN,
    W_ROOK,
    W_KNIGHT,
    W_BISHOP,
    W_QUEEN,
    W_KING,
    W_PAWN,
    EMPTY_CELL
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
    EIGHT,
    SEVEN,
    SIX,
    FIVE,
    FOUR,
    THREE,
    TWO,
    ONE
} Digit_Position;

void menu(sf::RenderWindow & window);


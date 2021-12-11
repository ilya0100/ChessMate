#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

// window
#define X_WINDOW 900
#define Y_WINDOW 750

// figures
#define SPRITE_SIZE 264

// board parameters
#define X_BOARD_SIZE 2400
#define Y_BOARD_SIZE 2400
#define X_PLAYSPACE (144 * SCALE_FACTOR)
#define Y_PLAYSPACE (144 * SCALE_FACTOR)
#define CELL_SIZE (264 * SCALE_FACTOR)

// buttons parameters
#define X_EXIT 119
#define Y_EXIT 43
#define X_BACK 284
#define Y_BACK 53

// scale
#define SCALE_FACTOR 0.2

static float size = SPRITE_SIZE * SCALE_FACTOR;

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

void menu(sf::RenderWindow & window);


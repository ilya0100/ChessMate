#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

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
        W_ROOK,     // 6
        W_KNIGHT,   // 7
        W_BISHOP,   // 8
        W_QUEEN,    // 9
        W_KING,     // 10
        W_PAWN,     // 11
        EMPTY_CELL  // 12
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


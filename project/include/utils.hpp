#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

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


#pragma once

#include <SFML/Graphics.hpp>
#include <string>

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

void menu(sf::RenderWindow & window);


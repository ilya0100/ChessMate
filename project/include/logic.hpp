#pragma once

#include "utils.hpp"

namespace Chess {

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

    class BoardLogic {
        figureName board[8][8];
        size_t current_pos_x;
        size_t current_pos_y;
        
        public:
            BoardLogic();

            void setFigurePosition(size_t x, size_t y);
            bool isMoveFigure(figureName figure, size_t x, size_t y) const;
    };

}  // namespace Chess
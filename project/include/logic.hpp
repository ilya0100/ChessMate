#pragma once

#include "utils.hpp"

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

namespace Chess {

    class BoardLogic {
        figureName board[8][8];
        int current_pos_x;
        int current_pos_y;
        
        public:
            BoardLogic();

            void setFigurePosition(int x, int y);
            NumCage getFigurePosition() const;
            bool isMoveFigure(figureName figure, int x, int y) const;
    };

}  // namespace Chess
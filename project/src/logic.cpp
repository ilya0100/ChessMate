#include "logic.hpp"

namespace Chess {

    BoardLogic::BoardLogic() {
        current_pos_x = 0;
        current_pos_y = 0;

        board[0][0] = B_ROOK;
        board[0][1] = B_KNIGHT;
        board[0][2] = B_BISHOP;
        board[0][3] = B_QUEEN;
        board[0][4] = B_KING;
        board[0][5] = B_BISHOP;
        board[0][6] = B_KNIGHT;
        board[0][0] = B_ROOK;

        board[7][0] = W_ROOK;
        board[7][1] = W_KNIGHT;
        board[7][2] = W_BISHOP;
        board[7][3] = W_QUEEN;
        board[7][4] = W_KING;
        board[7][5] = W_BISHOP;
        board[7][6] = W_KNIGHT;
        board[7][0] = W_ROOK;

        for (int j = 0; j < 8; j++) {
            board[1][j] = B_PAWN;
        }

        for (int j = 0; j < 8; j++) {
            board[6][j] = W_PAWN;
        }

        for (int i = 2; i < 6; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = EMPTY_CELL;
            }
        }
    }

    void BoardLogic::setFigurePosition(size_t x, size_t y) {
        current_pos_x = x;
        current_pos_y = y;
    }

    bool BoardLogic::isMoveFigure(figureName figure, size_t x, size_t y) const {
        switch (figure) {
            case B_ROOK:
                if (y - current_pos_y == 1 && 
                    (x - current_pos_x == 1 || x - current_pos_x == - 1)) {
                    return true;
                }

            case W_ROOK:
                if (y - current_pos_y == - 1 && 
                    (x - current_pos_x == 1 || x - current_pos_x == - 1)) {
                    return true;
                }

            default:
                break;
        }
    }

}  // namespace Chess
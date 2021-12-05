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
        board[0][7] = B_ROOK;

        board[7][0] = W_ROOK;
        board[7][1] = W_KNIGHT;
        board[7][2] = W_BISHOP;
        board[7][3] = W_QUEEN;
        board[7][4] = W_KING;
        board[7][5] = W_BISHOP;
        board[7][6] = W_KNIGHT;
        board[7][7] = W_ROOK;

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

    void BoardLogic::setFigurePosition(int x, int y) {
        current_pos_x = x;
        current_pos_y = y;
    }

    NumCage BoardLogic::getFigurePosition() const {
        NumCage cage;
        cage.x = current_pos_x;
        cage.y = current_pos_y;
        return cage;
    }

    bool BoardLogic::isMoveFigure(int x, int y) {
        figureName figure = board[current_pos_y][current_pos_x];

        if (x == current_pos_x && y == current_pos_y) {
            return false;
        }

        switch (figure) {
            case B_PAWN:
                if (x == current_pos_x && y - current_pos_y == 1) {
                    board[y][x] = B_PAWN;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_PAWN:
                if (x == current_pos_x && y - current_pos_y == - 1) {
                    board[y][x] = W_PAWN;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            case B_KING:
                if ((x - current_pos_x) * (x - current_pos_x) <= 1 &&
                    (y - current_pos_y) * (y - current_pos_y) <= 1) {
                    board[y][x] = B_KING;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_KING:
                if ((x - current_pos_x) * (x - current_pos_x) <= 1 && 
                    (y - current_pos_y) * (y - current_pos_y) <= 1) {
                    board[y][x] = W_KING;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            case B_QUEEN:
                if ((x - y) == (current_pos_x - current_pos_y) ||
                    (x + y) == (current_pos_x + current_pos_y) ||
                    x == current_pos_x || y == current_pos_y) {
                    board[y][x] = B_QUEEN;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_QUEEN:
                if ((x - y) == (current_pos_x - current_pos_y) ||
                    (x + y) == (current_pos_x + current_pos_y) ||
                    x == current_pos_x || y == current_pos_y) {
                    board[y][x] = W_QUEEN;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            case B_BISHOP:
                if ((x - y) == (current_pos_x - current_pos_y) ||
                    (x + y) == (current_pos_x + current_pos_y)) {
                    board[y][x] = B_BISHOP;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_BISHOP:
                if ((x - y) == (current_pos_x - current_pos_y) ||
                    (x + y) == (current_pos_x + current_pos_y)) {
                    board[y][x] = W_BISHOP;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            case B_KNIGHT:
                if ((x - current_pos_x) * (x - current_pos_x) + 
                    (y - current_pos_y) * (y - current_pos_y) == 5) {
                    board[y][x] = B_KNIGHT;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_KNIGHT:
                if ((x - current_pos_x) * (x - current_pos_x) + 
                    (y - current_pos_y) * (y - current_pos_y) == 5) {
                    board[y][x] = W_KNIGHT;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;
            
            case B_ROOK:
                if ((x == current_pos_x && y != current_pos_y) ||
                    (x != current_pos_x && y == current_pos_y)) {
                    board[y][x] = B_ROOK;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_ROOK:
                if ((x == current_pos_x && y != current_pos_y) ||
                    (x != current_pos_x && y == current_pos_y)) {
                    board[y][x] = W_ROOK;
                    board[current_pos_y][current_pos_x] = EMPTY_CELL;
                    return true;
                }
                break;

            default:
                break;
        }
        return false;
    }

}  // namespace Chess
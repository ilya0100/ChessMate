#include "logic.hpp"

namespace Chess {

    BoardLogic::BoardLogic() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = EMPTY_CELL;
            }
        }
    }

    void BoardLogic::setSide(Figure_Side side) {
        switch (side) {
        case WHITE:
            current_pos.x = 0;
            current_pos.y = 0;

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
            break;
        
        case BLACK:
            current_pos.x = 0;
            current_pos.y = 0;

            board[7][0] = B_ROOK;
            board[7][1] = B_KNIGHT;
            board[7][2] = B_BISHOP;
            board[7][3] = B_QUEEN;
            board[7][4] = B_KING;
            board[7][5] = B_BISHOP;
            board[7][6] = B_KNIGHT;
            board[7][7] = B_ROOK;

            board[0][0] = W_ROOK;
            board[0][1] = W_KNIGHT;
            board[0][2] = W_BISHOP;
            board[0][3] = W_QUEEN;
            board[0][4] = W_KING;
            board[0][5] = W_BISHOP;
            board[0][6] = W_KNIGHT;
            board[0][7] = W_ROOK;

            for (int j = 0; j < 8; j++) {
                board[6][j] = B_PAWN;
            }

            for (int j = 0; j < 8; j++) {
                board[1][j] = W_PAWN;
            }

            for (int i = 2; i < 6; i++) {
                for (int j = 0; j < 8; j++) {
                    board[i][j] = EMPTY_CELL;
                }
            }
            break;

        default:
            break;    
        }           
    }

    figureName BoardLogic::operator()(int x, int y) const {
        return board[y][x];
    }

    figureName& BoardLogic::operator()(int x, int y) {
        return board[y][x];
    }

    void BoardLogic::setFigurePosition(sf::Vector2u pos) {
        current_pos = pos;
    }

    sf::Vector2u BoardLogic::getFigurePosition() const {
        sf::Vector2u cage;
        cage = current_pos;
        return cage;
    }

    bool BoardLogic::isMoveFigure(int x, int y) {
        figureName figure = board[current_pos.y][current_pos.x];

        if (x == current_pos.x && y == current_pos.y) {
            return false;
        }

        switch (figure) {

            case B_PAWN:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if (y - current_pos.y == - 1 && (x == current_pos.x && 
                    board[y][x] == EMPTY_CELL ||
                    (x - current_pos.x == -1 || x - current_pos.x == 1) &&
                    board[y][x] != EMPTY_CELL) ||
                    y - current_pos.y == -2 && x == current_pos.x &&
                    current_pos.y == 6) {
                        board[y][x] = B_PAWN;
                        board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_PAWN:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if (y - current_pos.y == - 1 && (x == current_pos.x && 
                    board[y][x] == EMPTY_CELL ||
                    (x - current_pos.x == -1 || x - current_pos.x == 1) &&
                    board[y][x] != EMPTY_CELL) ||
                    y - current_pos.y == -2 && x == current_pos.x &&
                    current_pos.y == 6) {
                        board[y][x] = W_PAWN;
                        board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case B_KING:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if ((x - current_pos.x) * (x - current_pos.x) <= 1 &&
                    (y - current_pos.y) * (y - current_pos.y) <= 1) {
                    board[y][x] = B_KING;
                    board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_KING:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if ((x - current_pos.x) * (x - current_pos.x) <= 1 &&
                    (y - current_pos.y) * (y - current_pos.y) <= 1) {
                    board[y][x] = W_KING;
                    board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case B_QUEEN:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if (isFigureOnDiagonal(x, y) || isFigureOnLine(x, y)) {
                    board[y][x] = B_QUEEN;
                    board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_QUEEN:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if (isFigureOnDiagonal(x, y) || isFigureOnLine(x, y)) {
                    board[y][x] = W_QUEEN;
                    board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case B_BISHOP:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if (isFigureOnDiagonal(x, y)) {
                    board[y][x] = B_BISHOP;
                    board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_BISHOP:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if (isFigureOnDiagonal(x, y)) {
                    board[y][x] = W_BISHOP;
                    board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case B_KNIGHT:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if ((x - current_pos.x) * (x - current_pos.x) +
                    (y - current_pos.y) * (y - current_pos.y) == 5) {
                    board[y][x] = B_KNIGHT;
                    board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_KNIGHT:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if ((x - current_pos.x) * (x - current_pos.x) +
                    (y - current_pos.y) * (y - current_pos.y) == 5) {
                    board[y][x] = W_KNIGHT;
                    board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case B_ROOK:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if (isFigureOnLine(x, y)) {
                    board[y][x] = B_ROOK;
                    board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            case W_ROOK:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if (isFigureOnLine(x, y)) {
                    board[y][x] = W_ROOK;
                    board[current_pos.y][current_pos.x] = EMPTY_CELL;
                    return true;
                }
                break;

            default:
                break;
        }
        return false;
    }

    bool BoardLogic::isFigureOnLine(int x, int y) const {
        if (x == current_pos.x && y != current_pos.y) {
            y < current_pos.y ? y++ : y--;
            while (y != current_pos.y) {
                if (board[y][x] != EMPTY_CELL) {
                    return false;
                }
                y < current_pos.y ? y++ : y--;
            }
            return true;
        }

        if (x != current_pos.x && y == current_pos.y) {
            x < current_pos.x ? x++ : x--;
            while (x != current_pos.x) {
                if (board[y][x] != EMPTY_CELL) {
                    return false;
                }
                x < current_pos.x ? x++ : x--;
            }
            return true;
        }
        return false;
    }

    bool BoardLogic::isFigureOnDiagonal(int x, int y) const {
        if ((x - y) == (current_pos.x - current_pos.y) ||
            (x + y) == (current_pos.x + current_pos.y)) {
                y < current_pos.y ? y++ : y--;
                x < current_pos.x ? x++ : x--;
                while (x != current_pos.x || y != current_pos.y) {
                    if (board[y][x] != EMPTY_CELL) {
                        return false;
                    }
                    y < current_pos.y ? y++ : y--;
                    x < current_pos.x ? x++ : x--;
                }
                return true;
        }
        return false;
    }

    sf::Packet& operator<<(sf::Packet& packet, const BoardLogic& board) {
        for (int y = 7; y >= 0; y--) {
            for (int x = 0; x < 8; x ++) {
                packet << board(x, y);
            }
        }
        return packet;
    }

    sf::Packet& operator>>(sf::Packet& packet, BoardLogic& board) {

        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x ++) {
                int buffer;
                packet >> buffer;
                board(x, y) = (figureName)buffer;
            }
        }
        return packet;
    }

}  // namespace Chess

#include "logic.hpp"

namespace Chess {

    BoardLogic::BoardLogic() {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = EMPTY_CELL;
                threat_map[i][j] = false;
            }
        }
    }

    void BoardLogic::setSide(PlaySide side) {
        cur_side = side;

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

    void BoardLogic::upsideDown() {
        figureName buffer[8][8];
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                buffer[7 - i][j] = board[i][j];
            }
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = buffer[i][j];
            }
        }
    }

    void BoardLogic::changeSide() {
        if (cur_side == BLACK) {
            cur_side = WHITE;
        } else if (cur_side == WHITE) {
            cur_side = BLACK;
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
        // std::cout << "current_pos x: " << current_pos.x << " y: " << current_pos.y << std::endl;
    }

    sf::Vector2u BoardLogic::getFigurePosition() const {
        sf::Vector2u cage;
        cage = current_pos;
        return cage;
    }

    bool BoardLogic::isMoveFigure(int x, int y) {
        if (x == current_pos.x && y == current_pos.y) {
            return false;
        }

        bool flag = false;
        eaten_fig = board[y][x];
        switch (board[current_pos.y][current_pos.x]) {

            case B_PAWN:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if (y - current_pos.y == - 1 && (x == current_pos.x && 
                    board[y][x] == EMPTY_CELL ||
                    (x - current_pos.x == -1 || x - current_pos.x == 1) &&
                    (board[y][x] != EMPTY_CELL || enPassant())) ||
                    y - current_pos.y == -2 && x == current_pos.x &&
                    current_pos.y == 6 && board[y][x] == EMPTY_CELL) {
                        board[y][x] = B_PAWN;
                        flag = true;
                }
                break;

            case W_PAWN:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if (y - current_pos.y == - 1 && (x == current_pos.x && 
                    board[y][x] == EMPTY_CELL ||
                    (x - current_pos.x == -1 || x - current_pos.x == 1) &&
                    (board[y][x] != EMPTY_CELL || enPassant())) ||
                    y - current_pos.y == -2 && x == current_pos.x &&
                    current_pos.y == 6 && board[y][x] == EMPTY_CELL) {
                        board[y][x] = W_PAWN;
                        flag = true;
                }
                break;

            case B_KING:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if (((x - current_pos.x) * (x - current_pos.x) <= 1 &&
                    (y - current_pos.y) * (y - current_pos.y) <= 1) || castling(x, y)) {
                        bshort_castling = false;
                        blong_castling = false;
                        board[y][x] = B_KING;
                        flag = true;
                }
                break;

            case W_KING:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if (((x - current_pos.x) * (x - current_pos.x) <= 1 &&
                    (y - current_pos.y) * (y - current_pos.y) <= 1) || castling(x, y)) {
                        wshort_castling = false;
                        wlong_castling = false;
                        board[y][x] = W_KING;
                        flag = true;
                }
                break;

            case B_QUEEN:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if (isFigureOnDiagonal(x, y) || isFigureOnLine(x, y)) {
                    board[y][x] = B_QUEEN;
                    flag = true;
                }
                break;

            case W_QUEEN:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if (isFigureOnDiagonal(x, y) || isFigureOnLine(x, y)) {
                    board[y][x] = W_QUEEN;
                    flag = true;
                }
                break;

            case B_BISHOP:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if (isFigureOnDiagonal(x, y)) {
                    board[y][x] = B_BISHOP;
                    flag = true;
                }
                break;

            case W_BISHOP:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if (isFigureOnDiagonal(x, y)) {
                    board[y][x] = W_BISHOP;
                    flag = true;
                }
                break;

            case B_KNIGHT:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if ((x - current_pos.x) * (x - current_pos.x) +
                    (y - current_pos.y) * (y - current_pos.y) == 5) {
                    board[y][x] = B_KNIGHT;
                    flag = true;
                }
                break;

            case W_KNIGHT:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if ((x - current_pos.x) * (x - current_pos.x) +
                    (y - current_pos.y) * (y - current_pos.y) == 5) {
                    board[y][x] = W_KNIGHT;
                    flag = true;
                }
                break;

            case B_ROOK:
                if (board[y][x] <= B_PAWN) {
                    return false;
                }
                if (isFigureOnLine(x, y)) {
                    if (current_pos.x == 0 && current_pos.y == 7) {
                        blong_castling = false;
                    } else if (current_pos.x == 7 && current_pos.y == 7) {
                        bshort_castling = false;
                    }
                    board[y][x] = B_ROOK;
                    flag = true;
                }
                break;

            case W_ROOK:
                if (board[y][x] >= W_ROOK) {
                    return false;
                }
                if (isFigureOnLine(x, y)) {
                    if (current_pos.x == 0 && current_pos.y == 7) {
                        wlong_castling = false;
                    } else if (current_pos.x == 7 && current_pos.y == 7) {
                        wshort_castling = false;
                    }
                    board[y][x] = W_ROOK;
                    flag = true;
                }
                break;

            default:
                break;
        }
        if (flag) {
            board[current_pos.y][current_pos.x] = EMPTY_CELL;
            previos_fig = board[y][x];
            previos_move[0] = current_pos;
            previos_move[1].x = x;
            previos_move[1].y = y;
        } else {
            eaten_fig = EMPTY_CELL;
        }
        return flag;
    }

    bool BoardLogic::isGameOver() {
        checkGameState();
        if (check && !game_over) {
            sf::Vector2u temp = current_pos;
            game_over = isMate();
            setFigurePosition(temp);
        }
        // for (int y = 0; y < 8; ++y) {
        //     for (int x = 0; x < 8; ++x) {
        //         std::cout << threat_map[y][x] << " ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;
        return game_over;
    }

    bool BoardLogic::isCheck() {
        checkGameState();
        if (check) {
            cancelMove();
            return true;
        }
        return false;
    }

    bool BoardLogic::isMate() {
        for (int y = 0; y < 8; ++y) {
            for (int x = 0; x < 8; ++x) {
                current_pos.x = x;
                current_pos.y = y;

                if (cur_side == WHITE) {
                    switch (board[y][x]) {
                    case W_PAWN:
                        if (pawnTestMove(x, y)) {
                            return false;
                        }
                        break;

                    case W_KING:
                        if (kingTestMove(x, y)) {
                            return false;
                        }
                        break;

                    case W_KNIGHT:
                        if (knightTestMove(x, y)) {
                            return false;
                        }
                        break;

                    case W_ROOK:
                        if (lineTestMove(x, y)) {
                            return false;
                        }
                        break;

                    case W_BISHOP:
                        if (diagonalTestMove(x, y)) {
                            return false;
                        }
                        break;

                    case W_QUEEN:
                        if (lineTestMove(x, y) || diagonalTestMove(x, y)) {
                            return false;
                        }
                        break;

                    default:
                        break;
                    }
                } else {
                    switch (board[y][x]) {
                    case B_PAWN:
                        if (pawnTestMove(x, y)) {
                            return false;
                        }
                        break;

                    case B_KING:
                        if (kingTestMove(x, y)) {
                            return false;
                        }
                        break;

                    case B_KNIGHT:
                        if (knightTestMove(x, y)) {
                            return false;
                        }
                        break;

                    case B_ROOK:
                        if (lineTestMove(x, y)) {
                            return false;
                        }
                        break;

                    case B_BISHOP:
                        if (diagonalTestMove(x, y)) {
                            return false;
                        }
                        break;

                    case B_QUEEN:
                        if (lineTestMove(x, y) || diagonalTestMove(x, y)) {
                            return false;
                        }
                        break;

                    default:
                        break;
                    }
                }
            }
        }
        return true;
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

    bool BoardLogic::enPassant() {
        if (((previos_fig == B_PAWN && cur_side == WHITE) || (previos_fig == W_PAWN && cur_side == BLACK)) &&
            current_pos.y == (7 - previos_move[1].y) && (previos_move[0].y - previos_move[1].y) == 2) {
                board[7 - previos_move[1].y][previos_move[1].x] = EMPTY_CELL;
                return true;
        }
        return false;
    }

    bool BoardLogic::castling(int x, int y) {
        if ((wshort_castling || bshort_castling) && x == 6 && y == 7 &&
            !threat_map[y][x - 1] && !threat_map[y][x] && !check) {
                board[7][5] = board[7][7];
                board[7][7] = EMPTY_CELL;
                return true;
        }
        if ((wlong_castling || blong_castling) && x == 2 && y == 7 &&
            !threat_map[y][x + 1] && !threat_map[y][x] && !check) {
                board[7][3] = board[7][0];
                board[7][0] = EMPTY_CELL;
                return true;
        }
        return false;
    }

    void BoardLogic::checkGameState() {
        sf::Vector2u king_pos[2];
        int k = 0;
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++)  {
                threat_map[y][x] = false;
                if (board[y][x] == W_KING) {
                    k++;
                    if (cur_side == WHITE) {
                        king_pos[0].x = x;
                        king_pos[0].y = y;
                        board[y][x] = EMPTY_CELL;
                    }
                }
                if (board[y][x] == B_KING) {
                    k++;
                    if (cur_side == BLACK) {
                    king_pos[1].x = x;
                    king_pos[1].y = y;
                    board[y][x] = EMPTY_CELL;
                    }
                }
            }
        }
        if (k != 2) {
            game_over = true;
            return;
        }

        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                if (cur_side == BLACK) {
                    switch (board[y][x]) {
                    case W_PAWN:
                        setPawnThreat(x, y);
                        break;

                    case W_KING:
                        setKingThreat(x, y);
                        break;

                    case W_KNIGHT:
                        setKnightThreat(x, y);
                        break;

                    case W_ROOK:
                        setLineThreat(x, y);
                        break;

                    case W_BISHOP:
                        setDiagonalThreat(x, y);
                        break;

                    case W_QUEEN:
                        setDiagonalThreat(x, y);
                        setLineThreat(x, y);
                        break;

                    default:
                        break;
                    }
                } else {
                    switch (board[y][x]) {
                    case B_PAWN:
                        setPawnThreat(x, y);
                        break;

                    case B_KING:
                        setKingThreat(x, y);
                        break;

                    case B_KNIGHT:
                        setKnightThreat(x, y);
                        break;

                    case B_ROOK:
                        setLineThreat(x, y);
                        break;

                    case B_BISHOP:
                        setDiagonalThreat(x, y);
                        break;

                    case B_QUEEN:
                        setDiagonalThreat(x, y);
                        setLineThreat(x, y);
                        break;

                    default:
                        break;
                    }
                }
            }
        }
        if (cur_side == WHITE) {
            board[king_pos[0].y][king_pos[0].x] = W_KING;
        } else if (cur_side == BLACK) {
            board[king_pos[1].y][king_pos[1].x] = B_KING;
        }

        check = false;
        if (threat_map[king_pos[0].y][king_pos[0].x] == true && cur_side == WHITE) {
            check = true;
        } else if (threat_map[king_pos[1].y][king_pos[1].x] == true && cur_side == BLACK) {
            check = true;
        }
    }

    bool BoardLogic::isValidCoords(int x, int y) const {
        if (x < 0 || y < 0 || x > 7 || y > 7) {
            return false;
        }
        return true;
    }


    void BoardLogic::setPawnThreat(int x, int y) {
        if (board[y + 1][x + 1] == EMPTY_CELL && isValidCoords(x + 1, y + 1)) {
            threat_map[y + 1][x + 1] = true;
        }
        if (board[y + 1][x - 1] == EMPTY_CELL && isValidCoords(x - 1, y + 1)) {
            threat_map[y + 1][x - 1] = true;
        }
    }

    void BoardLogic::setKingThreat(int x, int y) {
        for (int i = - 1; i < 2; i++) {
            if (board[y + 1][x + i] == EMPTY_CELL && isValidCoords(x + i, y + 1)) {
                threat_map[y + 1][x + i] = true;
            }
            if (board[y - 1][x + i] == EMPTY_CELL && isValidCoords(x + i, y - 1)) {
                threat_map[y - 1][x + i] = true;
            }
        }
        if (board[y][x + 1] == EMPTY_CELL && isValidCoords(x + 1, y)) {
            threat_map[y][x + 1] = true;
        }
        if (board[y][x - 1] == EMPTY_CELL && isValidCoords(x - 1, y)) {
            threat_map[y][x - 1] = true;
        }
    }
    
    void BoardLogic::setKnightThreat(int x, int y) {
        if (board[y + 2][x + 1] == EMPTY_CELL && isValidCoords(x + 1, y + 2)) {
            threat_map[y + 2][x + 1] = true;
        }
        if (board[y + 2][x - 1] == EMPTY_CELL && isValidCoords(x - 1, y + 2)) {
            threat_map[y + 2][x - 1] = true;
        }
        if (board[y - 2][x + 1] == EMPTY_CELL && isValidCoords(x + 1, y - 2)) {
            threat_map[y - 2][x + 1] = true;
        }
        if (board[y - 2][x - 1] == EMPTY_CELL && isValidCoords(x - 1, y - 2)) {
            threat_map[y - 2][x - 1] = true;
        }
        if (board[y + 1][x + 2] == EMPTY_CELL && isValidCoords(x + 2, y + 1)) {
            threat_map[y + 1][x + 2] = true;
        }
        if (board[y + 1][x - 2] == EMPTY_CELL && isValidCoords(x - 2, y + 1)) {
            threat_map[y + 1][x - 2] = true;
        }
        if (board[y - 1][x + 2] == EMPTY_CELL && isValidCoords(x + 2, y - 1)) {
            threat_map[y - 1][x + 2] = true;
        }
        if (board[y - 1][x - 2] == EMPTY_CELL && isValidCoords(x - 2, y - 1)) {
            threat_map[y - 1][x - 2] = true;
        }
    }
    
    void BoardLogic::setLineThreat(int x, int y) {
        int i = 1;
        while (board[y][x + i] == EMPTY_CELL && isValidCoords(x + i, y)) {
            threat_map[y][x + i] = true;
            i++;
        }
        i = 1;
        while (board[y][x - i] == EMPTY_CELL && isValidCoords(x - i, y)) {
            threat_map[y][x - i] = true;
            i++;
        }
        i = 1;
        while (board[y + i][x] == EMPTY_CELL && isValidCoords(x, y + i)) {
            threat_map[y + i][x] = true;
            i++;
        }
        i = 1;
        while (board[y - i][x] == EMPTY_CELL && isValidCoords(x, y - i)) {
            threat_map[y - i][x] = true;
            i++;
        }
    }
    
    void BoardLogic::setDiagonalThreat(int x, int y) {
        int i = 1;
        while (board[y + i][x + i] == EMPTY_CELL && isValidCoords(x + i, y + i)) {
            threat_map[y + i][x + i] = true;
            i++;
        }
        i = 1;
        while (board[y + i][x - i] == EMPTY_CELL && isValidCoords(x - i, y + i)) {
            threat_map[y + i][x - i] = true;
            i++;
        }
        i = 1;
        while (board[y - i][x + i] == EMPTY_CELL && isValidCoords(x + i, y - i)) {
            threat_map[y - i][x + i] = true;
            i++;
        }
        i = 1;
        while (board[y - i][x - i] == EMPTY_CELL && isValidCoords(x - i, y - i)) {
            threat_map[y - i][x - i] = true;
            i++;
        }
    }

    bool BoardLogic::testMove(int x, int y) {
        if (isValidCoords(x, y) && isMoveFigure(x, y)) {
            checkGameState();
            cancelMove();
            if (!check) {
                return true;
            }
        }
        return false;
    }

    void BoardLogic::cancelMove() {
        board[previos_move[0].y][previos_move[0].x] = board[previos_move[1].y][previos_move[1].x];
        board[previos_move[1].y][previos_move[1].x] = eaten_fig;
    }

    bool BoardLogic::pawnTestMove(int x, int y) {
        for (int i = -1; i < 2; ++i) {
            if (testMove(x + i, y - 1)) {
                return true;
            }
        }
        if (testMove(x, y - 2)) {
            return true;
        }
        return false;
    }

    bool BoardLogic::kingTestMove(int x, int y) {
        for (int i = - 1; i < 2; i++) {
            if (testMove(x + i, y + 1)) {
                return true;
            }
            if (testMove(x + i, y - 1)) {
                return true;
            }
        }
        if (testMove(x + 1, y)) {
            return true;
        }
        if (testMove(x - 1, y)) {
            return true;
        }
        return false;
    }

    bool BoardLogic::knightTestMove(int x, int y) {
        if (testMove(x + 1, y + 2)) {
            return true;
        }
        if (testMove(x - 1, y + 2)) {
            return true;
        }
        if (testMove(x + 1, y - 2)) {
            return true;
        }
        if (testMove(x - 1, y - 2)) {
            return true;
        }
        if (testMove(x + 2, y + 1)) {
            return true;
        }
        if (testMove(x - 2, y + 1)) {
            return true;
        }
        if (testMove(x + 2, y - 1)) {
            return true;
        }
        if (testMove(x - 2, y - 1)) {
            return true;
        }
        return false;
    }

    bool BoardLogic::lineTestMove(int x, int y) {
        int i = 1;
        while (x + i < 8) {
            if (testMove(x + i, y)) {
                return true;
            }
            i++;
        }
        i = 1;
        while (x - i >= 0) {
            if (testMove(x - i, y)) {
                return true;
            }
            i++;
        }
        i = 1;
        while (y + i < 8) {
            if (testMove(x, y + i)) {
                return true;
            }
            i++;
        }
        i = 1;
        while (y - i >= 0) {
            if (testMove(x, y - i)) {
                return true;
            }
            i++;
        }
        return false;
    }

    bool BoardLogic::diagonalTestMove(int x, int y) {
        int i = 1;
        while (x + i < 8 && y + i < 8) {
            if (testMove(x + i, y + i)) {
                return true;
            }
            i++;
        }
        i = 1;
        while (x - i >= 0 && y + i < 8) {
            if (testMove(x - i, y + i)) {
                return true;
            }
            i++;
        }
        i = 1;
        while (x + i < 8 && y - i >= 0) {
            if (testMove(x + i, y - i)) {
                return true;
            }
            i++;
        }
        i = 1;
        while (x - i >= 0 && y - i >= 0) {
            if (testMove(x - i, y - i)) {
                return true;
            }
            i++;
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

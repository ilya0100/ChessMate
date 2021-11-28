#include "chess.hpp"
#include "figures.hpp"
#include "board.hpp"
#include "utils.h"

namespace Chess {

    void Figures::SetFigure(Figure_Name figure, Letter_Position letter, Digit_Position digit) {
        Figures::SetSprite(figure);
        figures[figure].setPosition(size * letter, size * digit);
    }

    void Figures::SetSprite(Figure_Name figure) {
        Chess::FigureTexture figure("images/piecesT.png");
        switch(figure) {
            case(B_ROOK):
                figures[B_ROOK].setTexture(figure.get_texture());
                figures[B_ROOK].setTextureRect(sf::IntRect(size * 4, size * 1, size, size));
                break;
            case(B_KHIGHT):
                figures[B_KNIGHT].setTexture(figure.get_texture());
                figures[B_KNIGHT].setTextureRect(sf::IntRect(size * 3, size * 1, size, size));
                break;
            case(B_BISHOP):
                figures[B_BISHOP].setTexture(figure.get_texture());
                figures[B_BISHOP].setTextureRect(sf::IntRect(size * 2, size * 1, size, size));
                break;
            case(B_QUEEN):
                figures[B_QUEEN].setTexture(figure.get_texture());
                figures[B_QUEEN].setTextureRect(sf::IntRect(size * 1, size * 1, size, size));
                break;
            case(B_KING):
                figures[B_KING].setTexture(figure.get_texture());
                figures[B_KING].setTextureRect(sf::IntRect(size * 0, size * 1, size, size));
                break;
            case(B_PAWN):
                figures[B_PAWN].setTexture(figure.get_texture());
                figures[B_PAWN].setTextureRect(sf::IntRect(size * 5, size * 1, size, size));
                break;
            case(W_ROOK):
                figures[W_ROOK].setTexture(figure.get_texture());
                figures[W_ROOK].setTextureRect(sf::IntRect(size * 4, size * 0, size, size));
                break;
            case(W_KHIGHT):
                figures[W_KNIGHT].setTexture(figure.get_texture());
                figures[W_KNIGHT].setTextureRect(sf::IntRect(size * 3, size * 0, size, size));
                break;
            case(W_BISHOP):
                figures[W_BISHOP].setTexture(figure.get_texture());
                figures[W_BISHOP].setTextureRect(sf::IntRect(size * 2, size * 0, size, size));
                break;
            case(W_QUEEN):
                figures[W_QUEEN].setTexture(figure.get_texture());
                figures[W_QUEEN].setTextureRect(sf::IntRect(size * 1, size * 0, size, size));
                break;
            case(W_KING):
                figures[W_KING].setTexture(figure.get_texture());
                figures[W_KING].setTextureRect(sf::IntRect(size * 0, size * 0, size, size));
                break;
            case(W_PAWN):
                figures[W_PAWN].setTexture(figure.get_texture());
                figures[W_PAWN].setTextureRect(sf::IntRect(size * 5, size * 0, size, size));
                break;
            case(VOID):
                break;
            default:
                    break;
        }
    }

    Rook::Rook(Figure_Name Rook, Figure_Side S) {
        if (Rook == W_ROOK) {
            Name = W_ROOK;
            switch(S) {
                case(LEFT):
                    Side = LEFT;
                    Position[1][1]
                    Figures::SetFigure(Rook, A, ONE);
                    break;
                case(RIGHT):
                    Side = RIGHT;
                    Figures::SetFigure(Rook, H, ONE);
                    break;
                default:
                    break;
            }
        }
        if (Rook == B_ROOK) {
            switch(S) {
                Name = B_ROOK;
                case(LEFT):
                    Side = LEFT;
                    Figures::SetFigure(Rook, A, EIGHT);
                    break;
                case(RIGHT):
                    Side = RIGHT;
                    Figures::SetFigure(Rook, H, EIGHT);
                    break;
                default:
                    break;
            }
        }
    }

    Knight::Knight(Figure_Name Knight, Figure_Side S) {
        if (Knight == W_KNIGHT) {
            Name = W_KNIGHT;
            switch(S) {
                case(LEFT):
                    Side = LEFT;
                    Figures::SetFigure(Knight, B, ONE);
                    break;
                case(RIGHT):
                    Side = RIGHT;
                    Figures::SetFigure(Knight, G, ONE);
                    break;
                default:
                    break;
            }
        }
        if (Knight == B_KNIGHT) {
            Name = B_KNIGHT;
            switch(S) {
                case(LEFT):
                    Figures::SetFigure(Knight, B, EIGHT);
                    Side = LEFT;
                    break;
                case(RIGHT):
                    Figures::SetFigure(Knight, G, EIGHT);
                    Side = RIGHT;
                    break;
                default:
                    break;
            }
        }
    }

    Bishop::Bishop(Figure_Name Bishop, Figure_Side S) {
        if (Bishop == W_BISHOP) {
            Name = W_BISHOP;
            switch(S) {
                case(LEFT):
                    Side = LEFT;
                    Figures::SetFigure(Bishop, C, ONE);
                    break;
                case(RIGHT):
                    Figures::SetFigure(Bishop, F, ONE);
                    Side = RIGHT;
                    break;
                default:
                    break;
            }
        }
        if (Bishop == B_BISHOP) {
            Name = B_BISHOP;
            switch(S) {
                case(LEFT):
                    Figures::SetFigure(Bishop, C, EIGHT);
                    Side = LEST;
                    break;
                case(RIGHT):
                    Figures::SetFigure(Bishop, F, EIGHT);
                    Side = RIGHT;
                    break;
            }
                default:
                    break;
        }
    }

    Queen::Queen(Figure_Name Queen) {
        switch(Queen) {
            case(W_QUEEN):
                Name = W_QUEEN;
                Figures::SetFigure(Queen, D, ONE);
                break;
            case(B_QUEEN):
                Name = B_QUEEN;
                Figures::SetFigure(Queen, D, EIGHT);
                break;
        default:
                break;
        }
    }

    King::King(Figure_Name King) {
        switch(Queen) {
            case(W_KING):
                Name = W_KING;
                Figures::SetFigure(King, E, ONE);
                break;
            case(B_KING):
                Name = B_KING;
                Figures::SetFigure(King, E, EIGHT);
                break;
        default:
                break;
        }
    }

    Pawn:Pawn(Figure_Name Pawn, Pawn_Number Number) {
        P_Number = Number;
        switch(Pawn) {
            case(W_PAWN):
                Name = W_PAWN;
                Figures::SetFigure(W_PAWN, Number, TWO);
                break;
            case(B_KING):
                Name = B_PAWN;
                Figures::SetFigure(W_PAWN, Number, SEVEN);
                break;
        default:
                break;
        }

    }






}
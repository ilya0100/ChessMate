#include "chess.hpp"
#include "board.hpp"

namespace Chess {

    Board::Board(const std::string filename) {
        texture.loadFromFile(filename, sf::IntRect(62, 62, 417, 417));
        sprite.setTexture(texture);
    }

    Board::PutAllFiguresOnBoard() {
        Rook::Rook White_Left_Rook(W_ROOK, LEFT);
        Rook::Rook White_Left_Rook(W_ROOK, RIGHT);
        Rook::Rook Black_Right_Rook(B_ROOK, LEFT);
        Rook::Rook Black_Right_Rook(B_ROOK, RIGHT);

        Knight::Knight White_Left_Knight(W_KNIGHT, LEFT);
        Knight::Knight White_Left_Knight(W_KNIGHT, RIGHT);
        Knight::Knight Black_Right_Knight(B_KNIGHT, LEFT);
        Knight::Knight Black_Right_Knight(B_KNIGHT, RIGHT);

        Bishop::Bishop White_Left_Bishop(W_BISHOP, LEFT);
        Bishop::Bishop White_Left_Bishop(W_BISHOP, RIGHT);
        Bishop::Bishop Black_Right_Bishop(B_BISHOP, LEFT;
        Bishop::Bishop Black_Right_Bishop(B_BISHOP, RIGHT);

        Queen::Queen White_Queen(W_QUEEN);
        Queen::Queen Black_Queen(B_QUEEN);

        King::King White_King(W_KING);
        King::King Black_King(B_KING);

        Pawn::Pawn White_Pawn_1(W_PAWN, FIRST);
        Pawn::Pawn White_Pawn_2(W_PAWN, SECOND);
        Pawn::Pawn White_Pawn_3(W_PAWN, THIRD);
        Pawn::Pawn White_Pawn_4(W_PAWN, FOURTH);
        Pawn::Pawn White_Pawn_5(W_PAWN, FIFTH);
        Pawn::Pawn White_Pawn_6(W_PAWN, SIXTH);
        Pawn::Pawn White_Pawn_7(W_PAWN, SEVENTH;
        Pawn::Pawn White_Pawn_8(W_PAWN, EIGHTH);

        Pawn::Pawn Black_Pawn_1(B_PAWN, FIRST);
        Pawn::Pawn Black_Pawn_2(B_PAWN, SECOND);
        Pawn::Pawn Black_Pawn_3(B_PAWN, THIRD);
        Pawn::Pawn Black_Pawn_4(B_PAWN, FOURTH);
        Pawn::Pawn Black_Pawn_5(B_PAWN, FIFTH);
        Pawn::Pawn Black_Pawn_6(B_PAWN, SIXTH);
        Pawn::Pawn Black_Pawn_7(B_PAWN, SEVENTH);
        Pawn::Pawn Black_Pawn_8(B_PAWN, EIGHTH);
    }
    //sf::Texture Board::get_texture() {
    //    return texture


    sf::Sprite Board::get_sprite() {
        return sprite;
    }

    FigureTexture::FigureTexture(std::string texture_file) {
        texture.loadFromFile(texture_file);
    }

    sf::Texture FigureTexture::get_texture() {
            return texture;
        }

    ChessFigure::ChessFigure(size_t new_x, size_t new_y) {
        x = new_x;
        y = new_y;
    }

    size_t ChessFigure::get_x() { return x; }
    size_t ChessFigure::get_y() { return y; }

}
#include "chess.hpp"

#define CELL_SIZE 50

namespace Chess {

    Board::Board(std::string filename) {
        get_texture().loadFromFile(filename, sf::IntRect(62, 62, 417, 417));
        get_sprite().setTexture(texture);
    }

    sf::Texture Board::get_texture() {
        return texture;
    }

    sf::Sprite Board::get_sprite() {
        return sprite;
    }

    FigureTexture::FigureTexture(std::string texture_file) {
        texture.loadFromFile(texture_file);
    }

    sf::Texture FigureTexture::get_texture() {
            return texture;
        }

    ChessFigure::ChessFigure(size_t new_x = 0, size_t new_y = 0) {
        x = new_x;
        y = new_y;
    }

    size_t ChessFigure::get_x() { return x; }
    size_t ChessFigure::get_y() { return y; }

    Pawn::Pawn(FigureTexture texture) {
        sprite.setTexture(texture.get_texture());
        sprite.setTextureRect(sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));
    }

    void Pawn::set_poositions(ChessFigure figure) {
        possible_positions_x.push_back(figure.get_x() + CELL_SIZE);
        possible_positions_y.push_back(figure.get_y() - CELL_SIZE);

        possible_positions_x.push_back(figure.get_x() - CELL_SIZE);
        possible_positions_y.push_back(figure.get_y() - CELL_SIZE);
    }
    
}  // namesapce Chess
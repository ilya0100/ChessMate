#include "chess.hpp"

#define CELL_SIZE 50

namespace Chess {

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
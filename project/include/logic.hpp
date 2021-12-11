#pragma once

#include "utils.hpp"

namespace Chess {

    class FigureTexture;

    class BoardLogic {
        figureName board[8][8];

        sf::Vector2u current_pos;
        
        public:
            BoardLogic();

            void setFigurePosition(sf::Vector2u pos);

            sf::Vector2u getFigurePosition() const;
            bool isMoveFigure(int x, int y);
            Figure_Side cur_side = WHITE;
            
            figureName operator()(int x, int y) const;
        
        private:
            bool isFigureOnLine(int x, int y) const;
            bool isFigureOnDiagonal(int x, int y) const;
    };

}  // namespace Chess
#pragma once

#include "utils.hpp"

namespace Chess {

    class FigureTexture;

    class BoardLogic {
        figureName board[8][8];

        int current_pos_x;
        int current_pos_y;
        
        public:
            BoardLogic();

            void setFigurePosition(int x, int y);

            NumCage getFigurePosition() const;
            bool isMoveFigure(int x, int y);
            
            figureName operator()(int i, int j) const;
    };

}  // namespace Chess
#pragma once

#include "utils.hpp"

namespace Chess {

    class FigureTexture;

    class BoardLogic {

        int current_pos_x;
        int current_pos_y;
        
        public:
            BoardLogic();
            figureName board[8][8];

            void setFigurePosition(int x, int y);
            NumCage getFigurePosition() const;
            bool isMoveFigure(int x, int y);
    };

}  // namespace Chess
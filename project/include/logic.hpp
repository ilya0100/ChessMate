#pragma once

#include "utils.hpp"

namespace Chess {

    class BoardLogic {

        protected:
            sf::Vector2u current_pos;
            PlaySide cur_side = WHITE;
            figureName board[8][8];

            sf::Vector2u previos_move[2];
            figureName previos_fig;
        
        public:
            BoardLogic();

            void setFigurePosition(sf::Vector2u pos);
            void setSide(PlaySide side = WHITE);
            void upsideDown();
            void changeSide();

            sf::Vector2u getFigurePosition() const;
            bool isMoveFigure(int x, int y);
            
            figureName operator()(int x, int y) const;
            figureName& operator()(int x, int y);

            friend sf::Packet& operator<<(sf::Packet& packet, const BoardLogic& board);
            friend sf::Packet& operator>>(sf::Packet& packet, BoardLogic& board);
        
        private:
            bool isFigureOnLine(int x, int y) const;
            bool isFigureOnDiagonal(int x, int y) const;
            bool enPassant();
    };

    // sf::Packet& operator<<(sf::Packet& packet, const BoardLogic& board);
    // sf::Packet& operator>>(sf::Packet& packet, BoardLogic& board);

}  // namespace Chess
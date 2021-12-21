#pragma once

#include "utils.hpp"
#include "iomanip"

namespace Chess {

    class BoardLogic {

        protected:
            sf::Vector2u current_pos;
            PlaySide cur_side = WHITE;
            figureName board[8][8];


            void checkGameState();
        
        public:
            BoardLogic();

            void setFigurePosition(sf::Vector2u pos);
            void setSide(PlaySide side = WHITE);
            void upsideDown();
            void changeSide();

            sf::Vector2u getFigurePosition() const;
            bool isMoveFigure(int x, int y);
            bool isGameOver();
            
            figureName operator()(int x, int y) const;
            figureName& operator()(int x, int y);

            friend sf::Packet& operator<<(sf::Packet& packet, const BoardLogic& board);
            friend sf::Packet& operator>>(sf::Packet& packet, BoardLogic& board);
        
        private:
            bool game_over = false;
            bool check = false;

            bool threat_map[8][8];

            sf::Vector2u previos_move[2];
            figureName previos_fig;

            bool isFigureOnLine(int x, int y) const;
            bool isFigureOnDiagonal(int x, int y) const;
            bool enPassant();

            bool isValidCoords(int x, int y) const;
            void setPawnThreat(int x, int y);
            void setKingThreat(int x, int y);
            void setKnightThreat(int x, int y);
            void setLineThreat(int x, int y);
            void setDiagonalThreat(int x, int y);
    };

    // sf::Packet& operator<<(sf::Packet& packet, const BoardLogic& board);
    // sf::Packet& operator>>(sf::Packet& packet, BoardLogic& board);

}  // namespace Chess
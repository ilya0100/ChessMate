#pragma once

#include "utils.hpp"

#define CELL_SIZE 50

namespace Chess {

    class FigureTexture {

        protected:
            sf::Texture texture;
            sf::Sprite sprite;

        public:
            FigureTexture(std::string texture_file);

            sf::Sprite getWPawnSprite();
            sf::Sprite getBPawnSprite();

            sf::Sprite getWRookSprite();
            sf::Sprite getBRookSprite();

            sf::Sprite getWKnightSprite();
            sf::Sprite getBKnightSprite();

            sf::Sprite getWElephantSprite();
            sf::Sprite getBElephantSprite();

            sf::Sprite getWQueenSprite();
            sf::Sprite getBQueenSprite();


            sf::Sprite getWKingSprite();
            sf::Sprite getBKingSprite();
    };

/*
    class Pawn: public FigureTexture {
            sf::Sprite w_sprite;
            sf::Sprite b_sprite;

        public:
            Pawn();

            sf::Sprite getWPawnSprite() const;
            sf::Sprite getBPawnSprite() const;
    };


    class Rook: public FigureTexture {
            sf::Sprite w_sprite;
            sf::Sprite b_sprite;
    
        public:
            Rook();
    
            sf::Sprite getWRookSprite() const;
            sf::Sprite getBRookSprite() const;
    };


    class Knight: public FigureTexture {
            sf::Sprite w_sprite;
            sf::Sprite b_sprite;
    
        public:
            Knight();
    
            sf::Sprite getWKnightSprite() const;
            sf::Sprite getBKnightSprite() const;
    };


    class Elephant: public FigureTexture {
            sf::Sprite w_sprite;
            sf::Sprite b_sprite;
    
        public:
            Elephant();
    
            sf::Sprite getWElephantSprite() const;
            sf::Sprite getBElephantSprite() const;
    };


    class Queen: public FigureTexture {
            sf::Sprite w_sprite;
            sf::Sprite b_sprite;
    
        public:
            Queen();
    
            sf::Sprite getWQueenSprite() const;
            sf::Sprite getBQueenSprite() const;
    };


    class King: public FigureTexture {
            sf::Sprite w_sprite;
            sf::Sprite b_sprite;
    
        public:
            King();
    
            sf::Sprite getWKingSprite() const;
            sf::Sprite getBKingSprite() const;
    };
*/
}
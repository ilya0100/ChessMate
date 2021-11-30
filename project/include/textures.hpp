#pragma once

#include "utils.hpp"

#define CELL_SIZE 50

static size_t size = 52;

namespace Chess {

    class BoardTexture {
            sf::Texture texture;
            sf::Sprite sprite;
            sf::Vector2i playSpace;

        public:
            BoardTexture(const std::string filename);

            void setPlaySpace(sf::Vector2i pos);

            sf::Sprite get_sprite();
    };

    class MenuTexture {
            sf::Texture texture;
            sf::Sprite sprite;
            sf::Vector2i playSpace;

        public:
            MenuTexture(const std::string filename);

            void setPlaySpace(sf::Vector2i pos);

            sf::Sprite get_sprite();
    };

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

    void loadPieces(sf::Sprite (&f)[32], int (&board)[8][8], FigureTexture figure);

}  // namespace Chess
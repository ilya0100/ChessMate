#pragma once

#include "utils.hpp"

#define CELL_SIZE 50

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

}  // namespace Chess

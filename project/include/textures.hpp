#pragma once

#include "utils.hpp"

#define SPRITE_SIZE 50
#define START_CAGE 143

namespace Chess {

    class BoardTexture {
            sf::Texture texture;
            sf::Sprite sprite;
            sf::Vector2i playSpace;

        public:
            BoardTexture(const std::string filename);

            void setPlaySpace(sf::Vector2i pos);

            void getBoardPosition(float x, float y);
            void setScaleBoard(float scale);

            sf::Sprite get_sprite();
    };

    class FigureTexture {

        protected:
            sf::Texture texture;
            sf::Sprite sprite;

        public:
            FigureTexture(std::string texture_file);

            void setScaleFigure(float scale);

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

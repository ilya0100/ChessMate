#pragma once

#include "utils.hpp"

static float size = SPRITE_SIZE * SCALE_FACTOR;
// static size_t size = 52;

namespace Chess {

    class BoardTexture {
            sf::Texture texture;
            sf::Sprite sprite;
            sf::Vector2i playSpace;

        public:
            BoardTexture(const std::string filename);

            void setBoardScale(float scale);
            void setPlaySpace(sf::Vector2i pos);

            sf::Sprite getSprite();
    };

    class MenuTexture {
            sf::Texture texture;
            sf::Sprite sprite;
            sf::Vector2i playSpace;

        public:
            MenuTexture(const std::string filename);

            void setPlaySpace(sf::Vector2i pos);

            sf::Sprite getSprite();
    };

    class FigureTexture {

        protected:
            sf::Sprite sprite;

            static sf::Texture texture;
            static figureName board[8][8];
            static bool isTexture;



        public:
            FigureTexture(std::string texture_file);
            FigureTexture();
            void setFigureScale(float scale);
            sf::Sprite getFigureSprite(figureName fn);

    };

    class Figures: public FigureTexture {

        protected:
            sf::Vector2f figurePos;
            sf::Vector2u figureSize;
            figureName name;
            Letter_Position letterPos;
            Digit_Position digitPos;

        public:
            Figures();
            void setSprite(figureName fn);
            static void SetFiguresToDefaultPositions(Figures (&f)[32]);
            static void DrawFigures(Figures (&f)[32], sf::RenderWindow (&window));

    };

    void loadPieces(sf::Sprite (&f)[32], int (&board)[8][8], FigureTexture figure);

}  // namespace Chess

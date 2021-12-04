#pragma once

#include "utils.hpp"

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
            static sf::Texture texture;

        protected:
            static sf::Sprite main_sprite;
            // static figureName board[8][8];
            // bool isTexture;



        public:
            // FigureTexture(std::string texture_file);
            FigureTexture();
            void setFigureScale(float scale);
            // sf::Sprite getFigureSprite(figureName figure_name);

    };

    class Figures: public FigureTexture {

        protected:
            sf::Vector2f figurePos;
            sf::Vector2u figureSize;

            Letter_Position letterPos;
            Digit_Position digitPos;

            figureName name;
            sf::Sprite sprite;
            // bool is_exists;


        public:

            Figures();
            // Figures(figureName name);

            void setSprite(figureName figure_name);
            void setFigurePos(int i, int j);
            void moveFigure(float x, float y);

            sf::Sprite getFigureSprite();
            figureName getName() const;
            sf::Vector2f getFigurePos() const;
            // bool isExists() const;
            // static void SetFiguresToDefaultPositions(Figures (&f)[32]);
            // static void DrawFigures(Figures (&f)[32], sf::RenderWindow (&window));

    };

    void loadPieces(Figures& figure, figureName figure_name, size_t i, size_t j);

}  // namespace Chess

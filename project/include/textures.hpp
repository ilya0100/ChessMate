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

        public:
            FigureTexture();
            
            void setFigureScale(float scale);
    };

    class Figures: public FigureTexture {

        protected:
            sf::Vector2f figurePos;
            sf::Vector2u figureSize;

            Letter_Position letterPos;
            Digit_Position digitPos;

            figureName name;
            sf::Sprite sprite;

        public:
            Figures();
            Figures(figureName fn);

            void setSprite(figureName figure_name);
            void setFigurePos(int i, int j);
            void setFigurePos(Letter_Position lp, Digit_Position dp);

            void moveFigure(float x, float y);
            void drawFigure(sf:: RenderWindow &window);

            sf::Sprite getFigureSprite();
            figureName getName() const;
            sf::Vector2f getFigurePos() const;

    };

    void loadPieces(Figures& figure, figureName figure_name, size_t i, size_t j);

}  // namespace Chess

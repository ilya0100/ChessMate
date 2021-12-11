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

    // test class
    class Button {
            sf::Texture texture;
            sf::Sprite sprite;
            sf::Vector2u size;
            // sf::Vector2f pos;

        public:
            Button();
            Button(const std::string filename);

            void setButton(const std::string filename);
            void setSize(size_t x, size_t y);
            void setPosButton(float x, float y);

            sf::Sprite& getSprite();
            sf::Vector2u getSize();
            // sf::Vector2f getPosButton();
            // TODO: method setPos 

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
            sf::Vector2f spritePos;
            sf::Vector2u spriteSize;

            sf::Vector2u figurePos;

            figureName name;
            sf::Sprite sprite;

        public:
            Figures();
            Figures(figureName fn);

            void setSprite(figureName figure_name);
            void setFigurePos(int i, int j);
            void setSpritePos(float x, float y);
            // void setFigurePos(Letter_Position lp, Digit_Position dp);

            void moveFigure(float x, float y);
            void drawFigure(sf:: RenderWindow &window);

            sf::Vector2u getFigurePos() const;
            sf::Sprite getFigureSprite() const;
            figureName getName() const;
            sf::Vector2f getSpritePos() const;

    };

    void loadPieces(Figures& figure, figureName figure_name, size_t i, size_t j);

}  // namespace Chess

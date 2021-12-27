#pragma once

#include "utils.hpp"
#include <fstream>

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



    class Button {
            sf::Texture texture;
            sf::Sprite sprite;
            sf::Vector2f size;
            sf::Vector2f pos;

        public:
            Button();
            Button(const std::string filename);

            void setButton(const std::string filename);
            void setSize(float x, float y);
            void setPosition(float x, float y);

            sf::Sprite& getSprite();
            sf::Vector2f getSize();
            sf::Vector2f getPosition();

            bool isTouch(Window& window);
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
            static bool isDefined;
            static std::string pathfile;

        public:
            FigureTexture();
            static void setMain_sprite(const std::string filename);
            static void saveMain_sprite();
            static std::string getPath() {return pathfile;}
            static void defineMain_sprite();
            void setFigureScale(float scale);
    };
 
    class Figures: public FigureTexture {

        protected:
            sf::Vector2f spritePos;
            sf::Vector2u spriteSize;

            sf::Vector2u figurePos;

            figureName name;
            PlaySide side;
            sf::Sprite sprite;

        public:
            Figures();
            Figures(figureName fn);
            PlaySide getSide();

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


}  // namespace Chess

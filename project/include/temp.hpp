/*#pragma once

#include "utils.hpp"

#define SPRITE_SIZE 50

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

        private:

        protected:
            sf::Sprite sprite;
            static sf::Texture texture;
            static figureName board[8][8];


        public:
            FigureTexture();
            FigureTexture(std::string texture_file);
            sf::Sprite getFigureSprite(figureName fn);
    };

    class Figures: public FigureTexture {

        protected:
            sf::Vector2f figurePos;
            figureName name;

        public:
            Figures();
            Figures(figureName fn);

    };

    void loadPieces(sf::Sprite (&f)[100], int (&board)[8][8], FigureTexture figure);
    void loadPieces(sf::Sprite (&f)[100], figureName (&board)[8][8], FigureTexture figures);

}  // namespace Chess
*/
#pragma once

#include "utils.hpp"

// figures
// #define SPRITE_SIZE 264

// board parameters
#define X_BOARD_SIZE 2400
#define Y_BOARD_SIZE 2400
#define X_PLAYSPACE (144 * SCALE_FACTOR)
#define Y_PLAYSPACE (144 * SCALE_FACTOR)
#define CELL_SIZE (264 * SCALE_FACTOR)

// window
#define X_SCALE_W 2
#define Y_SCALE_W 1.3
#define X_WINDOW (X_BOARD_SIZE * X_SCALE_W * SCALE_FACTOR)
#define Y_WINDOW (Y_BOARD_SIZE * Y_SCALE_W * SCALE_FACTOR)

// buttons parameters
#define X_EXIT 119
#define Y_EXIT 43
#define X_BACK 284
#define Y_BACK 53

// scale
#define SCALE_FACTOR 0.2

#define TSPRITE_SIZE (SPRITE_SIZE * SCALE_FACTOR)

// static float size = SPRITE_SIZE * SCALE_FACTOR;

namespace Chess {
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

    class MenuTexture {
            sf::Texture texture;
            sf::Sprite sprite;
            sf::Vector2i playSpace;

        public:
            MenuTexture(const std::string filename);

            void setPlaySpace(sf::Vector2i pos);

            sf::Sprite getSprite();
    };

    void startMenu(sf::RenderWindow & window);

    void chooseMenu(sf::RenderWindow & window);
}

#pragma once

#include "utils.hpp"
#include <stdlib.h>

// figures
// #define SPRITE_SIZE 264



// static float size = SPRITE_SIZE * SCALE_FACTOR;

namespace Chess {
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

    void startMenu(Window & window, Flags& flags);

    void selectMode(Window& window, Flags& flags);
    void selectH(Window& window, Flags& flags);

    void Test(Window & window, Flags& flags);
    void startMenuN(Window & window, Flags& flags);
}

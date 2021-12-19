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
            sf::Vector2u size;
            sf::Vector2f pos;

        public:
            Button();
            Button(const std::string filename);

            void setButton(const std::string filename);
            void setSize(size_t x, size_t y);
            void setPosButton(float x, float y);

            sf::Sprite& getSprite();
            sf::Vector2u getSize();
            sf::Vector2f getPosButton();
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

    void startMenu(sf::RenderWindow & window, Flags& flags);

    void selectMode(sf::RenderWindow& window, Flags& flags);
    void selectH(sf::RenderWindow& window, Flags& flags);


    void startMenuN(Window & window);
}

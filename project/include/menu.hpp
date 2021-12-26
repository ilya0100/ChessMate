#pragma once

#include "gameplay.hpp"
#include <cstring>
#include <iostream>

// figures
// #define SPRITE_SIZE 264



// static float size = SPRITE_SIZE * SCALE_FACTOR;

namespace Chess {

    void startMenu(Window & window);

    void selectMode(Window& window);
    void selectH(Window& window);

    // create and join menu's
    void createGameMenu(Window & window, Gameplay& gameplay);
    std::string joinGameMenu(Window& window);

    void Test(Window & window);
    void startMenuN(Window & window);

    void startGame(Window& window, GameMode mode);

    /*class TextField {
        private:
            size_t maxChars;
            sf::Font font;
            std::string tempBuffer;
            bool shouldEnter;



        public:
            TextField();


            std::string getText() const;
            void setPosition(float x, float y);
            bool contains(sf::Vector2f point) const;
            void setFocus(bool focus);
            void handleInput(sf::Event event);

            // void draw(sf::Text text) override;


    };*/

}  // namespace Chess

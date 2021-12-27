#pragma once

#include "gameplay.hpp"
#include <cstring>
#include <iostream>

// figures
// #define SPRITE_SIZE 264




namespace Chess {

    //начальное меню
    void startMenu(Window & window);
    //^
    //выбор режима игры
    void selectMode(Window& window);
    // ^
    void selectH(Window& window);
    // ^
    // create and join menu's
    void createGameMenu(Window & window, Gameplay& gameplay);
    std::string joinGameMenu(Window& window);

    // настройки
    void options(Window& window);
    // ^
    void optionsTexture(Window& window);
    void setNewScreen(Window& window);


    // create and join menu's
    void createGameMenu(Window & window, Gameplay& gameplay);
    std::string joinGameMenu(Window& window);


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

#pragma once

#include "gameplay.hpp"

// figures
// #define SPRITE_SIZE 264



// static float size = SPRITE_SIZE * SCALE_FACTOR;

namespace Chess {

    void startMenu(Window & window);

    void selectMode(Window& window);
    void selectH(Window& window);

    // create and join menu's
    void createGameMenu(Window & window);
    void joinGameMenu(Window& window);

    void Test(Window & window);
    void startMenuN(Window & window);

    void startGame(Window& window, GameMode mode);

    /*class TextField : public sf::Transformable, public sf::Drawable {
        private:
            size_t m_size;
            sf::Font m_font;
            std::string m_text;
            sf::RectangleShape m_rect;
            bool m_hasfocus;
            sf::Text text; 

        public:
            TextField(size_t maxChars): m_size(maxChars),
                                        m_rect(sf::Vector2f(15 * maxChars, 20)),
                                        m_hasfocus(false) {
                    m_font.loadFromFile("./Fonts/font.TTF");
                    m_rect.setOutlineThickness(2);
                    m_rect.setFillColor(sf::Color::White);
                    m_rect.setOutlineThickness(2);
                    m_rect.setPosition(this->getPosition());
                }

            std::string getText() const;
            void setPosition(float x, float y);
            bool contains(sf::Vector2f point) const;
            void setFocus(bool focus);
            void handleInput(sf::Event event);

            // void draw(sf::Text text) override;


    };*/

}  // namespace Chess

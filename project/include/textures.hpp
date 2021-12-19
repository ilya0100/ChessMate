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

    //text entered

    class TextField : public sf::Transformable, public sf::Drawable{
    public:
        TextField(unsigned int maxChars) :
            m_size(maxChars),
            m_rect(sf::Vector2f(15 * m_size, 20)), // 15 pixels per char, 20 pixels height, you can tweak
            m_hasfocus(false)
        {
            m_font.loadFromFile("project/Fonts/font.TTF"); // I'm working on Windows, you can put your own font instead
            m_rect.setOutlineThickness(2);
            m_rect.setFillColor(sf::Color::White);
            m_rect.setOutlineColor(sf::Color(127,127,127));
            m_rect.setPosition(this->getPosition());
        }

    private:
        unsigned int m_size;
        sf::Font m_font;
        std::string m_text;
        sf::RectangleShape m_rect;
        bool m_hasfocus;
};

}  // namespace Chess

#include "utils.hpp"
#include "textures.hpp"

namespace Chess {

    // объявляем статические переменные
    sf::Texture FigureTexture::texture;
    sf::Sprite FigureTexture::main_sprite;

    ///////////////////Board//////////////////////////////////////////////
    BoardTexture::BoardTexture(const std::string filename) {
        texture.loadFromFile(filename, sf::IntRect(0, 0, X_BOARD_SIZE, X_BOARD_SIZE));
        sprite.setTexture(texture);
    }

    void BoardTexture::setBoardScale(float scale) {
        sprite.setScale(scale, scale);
    }

    void BoardTexture::setPlaySpace(sf::Vector2i pos) {
        playSpace.x = pos.x;
        playSpace.y = pos.y;
    }

    sf::Sprite BoardTexture::getSprite() {
        return sprite;
    }

    //////////////////////////Menu//////////////////////////////////////////
    MenuTexture::MenuTexture(const std::string filename) {
        texture.loadFromFile(filename, sf::IntRect(0, 0, 590, 590));
        sprite.setTexture(texture);
    }

    sf::Sprite MenuTexture::getSprite() {
        return sprite;
    }

    ////////////////////////Buttons///////////////////////////////////////////
    Button::Button(const std::string filename) {
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
    }

    void Button::setButton(const std::string filename) {
        texture.loadFromFile(filename);
        sprite.setTexture(texture);
    }

    void Button::setSize(float x, float y) {
        size.x = x;
        size.y = y;
    }

 	void Button::setPosition(float x, float y) {
		sprite.setPosition(x, y);
		pos.x = x;
    	pos.y = y;
    }

    sf::Sprite& Button::getSprite() { return sprite; }
    sf::Vector2f Button::getSize() { return size; }
    sf::Vector2f Button::getPosition() { return pos; }

    bool Button::isTouch(Window& window) {

        return sf::IntRect(pos.x * window.getRatio().x,
                    pos.y * window.getRatio().y,
                        size.x * window.getRatio().x,
                        size.y * window.getRatio().y).
                            contains(sf::Mouse::getPosition(window));

    }



    // text Entered

    const std::string Chess::TextField::getText() const {
        return m_text;
    }

    void Chess::TextField::setPosition(float x, float y){
        sf::Transformable::setPosition(x, y);
        m_rect.setPosition(x, y);
    }

    bool Chess::TextField::contains(sf::Vector2f point) const{
        return m_rect.getGlobalBounds().contains(point);
    }

    void Chess::TextField::setFocus(bool focus){
        m_hasfocus = focus;
        if (focus) {
         m_rect.setOutlineColor(sf::Color::Blue);
        } else {
            m_rect.setOutlineColor(sf::Color(127, 127, 127)); // Gray color
        }
    }

    void Chess::TextField::handleInput(sf::Event e){
        if (!m_hasfocus || e.type != sf::Event::TextEntered)
            return;

        if (e.text.unicode == 8){   // Delete key
            m_text = m_text.substr(0, m_text.size() - 1);
        }
        else if (m_text.size() < m_size){
            m_text += e.text.unicode;
        }
    }


    ///////////////////////FigureTexture///////////////////////////////////////////
    FigureTexture::FigureTexture() {
        FigureTexture::texture.loadFromFile("images/piecesTru.png");
        main_sprite.setTexture(texture);
    }

    void FigureTexture::setFigureScale(float scale) {
        main_sprite.setScale(scale, scale);
    }

    ////////////////////////Figures///////////////////////////////////////////////////////
    Figures::Figures() {
        name = EMPTY_CELL;
    }

    Figures::Figures(figureName fn) {
        setSprite(fn);
        name = fn;
    }

    PlaySide Figures::getSide() { return side;}

    void Figures::setSprite(figureName figure_name) {
        name = figure_name;
        sprite = main_sprite;
        if (name <= B_PAWN)
            side = BLACK;
        if (name >= W_ROOK)
            side = WHITE;

        switch (name) {
        case W_PAWN:
            sprite.setTextureRect(sf::IntRect(5 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
            break;

        case B_PAWN:
            sprite.setTextureRect(sf::IntRect(5 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            break;
            
        case W_ROOK:
            sprite.setTextureRect(sf::IntRect(4 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
            break;

        case B_ROOK:
            sprite.setTextureRect(sf::IntRect(4 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            break;

        case W_KNIGHT:
            sprite.setTextureRect(sf::IntRect(3 * SPRITE_SIZE , 0, SPRITE_SIZE, SPRITE_SIZE));
            break;

        case B_KNIGHT:
            sprite.setTextureRect(sf::IntRect(3 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            break;

        case W_BISHOP:
            sprite.setTextureRect(sf::IntRect(2 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
            break;

        case B_BISHOP:
            sprite.setTextureRect(sf::IntRect(2 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            break;

        case W_QUEEN:
            sprite.setTextureRect(sf::IntRect(1 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
            break;

        case B_QUEEN:
            sprite.setTextureRect(sf::IntRect(1 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            break;

        case W_KING:
            sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
            break;

        case B_KING:
            sprite.setTextureRect(sf::IntRect(0, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            break;

        default:
            break;
        }
        sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
    }

    void Figures::setFigurePos(int i, int j) {
        spritePos.x = X_PLAYSPACE + SCALE_FACTOR * SPRITE_SIZE * i;
        spritePos.y = Y_PLAYSPACE + SCALE_FACTOR * SPRITE_SIZE * j;
        // spritePos.x = SCALE_FACTOR * (X_PLAYSPACE + SPRITE_SIZE * i);
        // spritePos.y = SCALE_FACTOR * (Y_PLAYSPACE + SPRITE_SIZE * j);
        sprite.setPosition(spritePos.x, spritePos.y);

        figurePos.x = i;
        figurePos.y = j;
    }

    void Figures::setSpritePos(float x, float y) {
        spritePos.x = x;
        spritePos.y = y;
        sprite.setPosition(spritePos.x, spritePos.y);
    }

    /*
    void Figures::setFigurePos(Letter_Position lp, Digit_Position dp) {
        letterPos = lp;
        digitPos = dp;
        spritePos.x = SCALE_FACTOR * (X_PLAYSPACE + SPRITE_SIZE * (float)lp);
        spritePos.y = SCALE_FACTOR * (Y_PLAYSPACE + SPRITE_SIZE * (float)dp);
        sprite.setPosition(spritePos.x, spritePos.y);
    }
    */

    void Figures::drawFigure(sf:: RenderWindow &window) {
        window.draw(sprite);
    }

    void Figures::moveFigure(float x, float y) {
        sprite.setPosition(x, y);
    }

    sf::Vector2u Figures::getFigurePos() const {
        return figurePos;
    }

    figureName Figures::getName() const {
        return name;
    }

    sf::Vector2f Figures::getSpritePos() const {
        return spritePos;
    }

    sf::Sprite Figures::getFigureSprite() const{
        return sprite;
    }

    // Text entered




}  // namespace Chess

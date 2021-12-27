#include "utils.hpp"
#include "textures.hpp"


void settings::setSF(float sf) {
	std::ofstream out("./settings/screenSize.dat");
        if (out.is_open()) {
			out << sf << std::endl;
        }
        out.close();

    }

float settings::getSffromFile() {
    float buf;
    std::ifstream in("./settings/screenSize.dat");
    if (in.is_open())
        in >> buf;
    return buf;
}

namespace Chess {

    // объявляем статические переменные
    sf::Texture FigureTexture::texture;
    sf::Sprite FigureTexture::main_sprite;
    std::string FigureTexture::pathfile;
    bool FigureTexture::isDefined = false;

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



    ///////////////////////FigureTexture///////////////////////////////////////////
    FigureTexture::FigureTexture() {
        if (!isDefined) {
            std::ifstream in("./settings/default_pieces.dat");
            if (in.is_open())
                getline(in, pathfile);
            in.close();
            FigureTexture::texture.loadFromFile(pathfile);
            main_sprite.setTexture(texture);
        }
    }

    void FigureTexture::setMain_sprite(std::string filename) {
        isDefined = true;
        pathfile = filename;
        if (FigureTexture::texture.loadFromFile(filename))
            main_sprite.setTexture(texture);
        else
            isDefined = false;
    }

    void FigureTexture::saveMain_sprite() {
        std::ofstream out("./settings/default_pieces.dat");
        if (out.is_open()) {
            out << pathfile << std::endl;
        }
        out.close();
    }



    void FigureTexture::defineMain_sprite() {
        if (!isDefined) {
            std::ifstream in("./settings/default_pieces.dat");
            if (in.is_open())
                getline(in, pathfile);
            in.close();
            FigureTexture::texture.loadFromFile(pathfile);
            main_sprite.setTexture(texture);
        }
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
            sprite.setTextureRect(sf::IntRect(5 * settings::sprite_size, 0, settings::sprite_size, settings::sprite_size));
            break;

        case B_PAWN:
            sprite.setTextureRect(sf::IntRect(5 * settings::sprite_size, 1 * settings::sprite_size, settings::sprite_size, settings::sprite_size));
            break;

        case W_ROOK:
            sprite.setTextureRect(sf::IntRect(4 * settings::sprite_size, 0, settings::sprite_size, settings::sprite_size));
            break;

        case B_ROOK:
            sprite.setTextureRect(sf::IntRect(4 * settings::sprite_size, 1 * settings::sprite_size, settings::sprite_size, settings::sprite_size));
            break;

        case W_KNIGHT:
            sprite.setTextureRect(sf::IntRect(3 * settings::sprite_size , 0, settings::sprite_size, settings::sprite_size));
            break;

        case B_KNIGHT:
            sprite.setTextureRect(sf::IntRect(3 * settings::sprite_size, 1 * settings::sprite_size, settings::sprite_size, settings::sprite_size));
            break;

        case W_BISHOP:
            sprite.setTextureRect(sf::IntRect(2 * settings::sprite_size, 0, settings::sprite_size, settings::sprite_size));
            break;

        case B_BISHOP:
            sprite.setTextureRect(sf::IntRect(2 * settings::sprite_size, 1 * settings::sprite_size, settings::sprite_size, settings::sprite_size));
            break;

        case W_QUEEN:
            sprite.setTextureRect(sf::IntRect(1 * settings::sprite_size, 0, settings::sprite_size, settings::sprite_size));
            break;

        case B_QUEEN:
            sprite.setTextureRect(sf::IntRect(1 * settings::sprite_size, 1 * settings::sprite_size, settings::sprite_size, settings::sprite_size));
            break;

        case W_KING:
            sprite.setTextureRect(sf::IntRect(0, 0, settings::sprite_size, settings::sprite_size));
            break;

        case B_KING:
            sprite.setTextureRect(sf::IntRect(0, 1 * settings::sprite_size, settings::sprite_size, settings::sprite_size));
            break;

        default:
            break;
        }
        sprite.setScale(settings::getSf() , settings::getSf() );
    }

    void Figures::setFigurePos(int i, int j) {
        spritePos.x = settings::getPsX() + settings::getSf()  * settings::sprite_size * i;
        spritePos.y = settings::getPsY() + settings::getSf()  * settings::sprite_size * j;
        // spritePos.x = settings::getSf()  * (X_PLAYSPACE + settings::sprite_size * i);
        // spritePos.y = settings::getSf()  * (Y_PLAYSPACE + settings::sprite_size * j);
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
        spritePos.x = settings::getSf()  * (X_PLAYSPACE + settings::sprite_size * (float)lp);
        spritePos.y = settings::getSf()  * (Y_PLAYSPACE + settings::sprite_size * (float)dp);
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

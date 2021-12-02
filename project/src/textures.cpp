#include "textures.hpp"


namespace Chess {

    // объявляем статические переменные
    bool FigureTexture::isTexture = false;
    sf::Texture FigureTexture::texture;
    figureName FigureTexture::board[8][8] = {{B_ROOK    , B_KNIGHT  , B_BISHOP  , B_QUEEN   , B_KING    , B_BISHOP  , B_KNIGHT  , B_ROOK    },
                                             {B_PAWN    , B_PAWN    , B_PAWN    , B_PAWN    , B_PAWN    , B_PAWN    , B_PAWN    , B_PAWN    },
                                             {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
                                             {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
                                             {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
                                             {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
                                             {W_PAWN    , W_PAWN    , W_PAWN    , W_PAWN    , W_PAWN    , W_PAWN    , W_PAWN    , W_PAWN    },
                                             {W_ROOK    , W_KNIGHT  , W_BISHOP  , W_QUEEN   , W_KING    , W_BISHOP  , W_KNIGHT  , W_ROOK    }};

    BoardTexture::BoardTexture(const std::string filename) {
        texture.loadFromFile(filename, sf::IntRect(62, 62, 417, 417));
        sprite.setTexture(texture);
    }

    MenuTexture::MenuTexture(const std::string filename) {
        texture.loadFromFile(filename, sf::IntRect(0, 0, 590, 590));
        sprite.setTexture(texture);
    }

    sf::Sprite MenuTexture::get_sprite() {
        return sprite;
    }



    sf::Sprite BoardTexture::get_sprite() {
        return sprite;
    }

    // sf::Vector2i getPlaySpace() {
    //     sf::Vector2i playSpace;
    //     playSpace.x = sprite.getPosition().x + begin.x;
    // }

    void BoardTexture::setPlaySpace(sf::Vector2i pos) {
        playSpace.x = pos.x;
        playSpace.y = pos.y;
    }

    FigureTexture::FigureTexture(std::string texture_file) {
        if (!isTexture) {
            texture.loadFromFile(texture_file);
            sprite.setTexture(texture);
            sprite.setTextureRect(sf::IntRect(5, 1, SPRITE_SIZE, SPRITE_SIZE));
            isTexture = true;
        }
    }

    FigureTexture::FigureTexture() {
        if (!isTexture) {
            FigureTexture::texture.loadFromFile("images/piecesT.png");
            sprite.setTexture(texture);
            isTexture = true;
        }


    }

    Figures::Figures() {
        if (!isTexture) {
            FigureTexture::texture.loadFromFile("images/piecesT.png");
            sprite.setTexture(texture);
            isTexture = true;
        }
    }

    void Figures::setSprite(figureName fn) {
        if (!isTexture) {
            FigureTexture::texture.loadFromFile("images/piecesT.png");
            sprite.setTexture(texture);
            isTexture = true;
        }
        name = fn;
        figureSize.x = SPRITE_SIZE;
        figureSize.y = SPRITE_SIZE;
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
            sprite.setTextureRect(sf::IntRect(3 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
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
            sprite.setTextureRect(sf::IntRect(2 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            break;
        default:
            break;
        }
    }

    void Figures::setPos(Letter_Position lp, Digit_Position dp) {
        letterPos = lp;
        digitPos = dp;
        figurePos.x = (float)lp * (float)size;
        figurePos.y = (float)dp * (float)size;
        sprite.setPosition(figurePos.x, figurePos.y);


    }

    void Figures::drawFigure(sf::RenderWindow (&window)) {
        window.draw(sprite);
    }

    void Figures::SetFiguresToDefaultPositions(Figures (&f)[32]) {
        int k = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                //printf("%d\n", j);
                if (board[i][j] != EMPTY_CELL) {
                    f[k].setSprite(FigureTexture::board[i][j]);
                    k++;
                }
            }
        }
    }

    void Figures::DrawFigures(Figures (&f)[32], sf::RenderWindow (&window)) {
        SetFiguresToDefaultPositions(f);

        for (size_t i = 0; i < 32; i++) {
            window.draw(f[i].sprite);
        }
    }
    // Pawn


    sf::Sprite FigureTexture::getFigureSprite(figureName fn) {
        switch (fn)
        {
        case W_PAWN:
            sprite.setTextureRect(sf::IntRect(5 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case B_PAWN:
            sprite.setTextureRect(sf::IntRect(5 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case W_ROOK:
            sprite.setTextureRect(sf::IntRect(4 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case B_ROOK:
            sprite.setTextureRect(sf::IntRect(4 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case W_KNIGHT:
            sprite.setTextureRect(sf::IntRect(3 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case B_KNIGHT:
            sprite.setTextureRect(sf::IntRect(3 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case W_BISHOP:
            sprite.setTextureRect(sf::IntRect(2 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case B_BISHOP:
            sprite.setTextureRect(sf::IntRect(2 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case W_QUEEN:
            sprite.setTextureRect(sf::IntRect(1 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case B_QUEEN:
            sprite.setTextureRect(sf::IntRect(1 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case W_KING:
            sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;
        case B_KING:
            sprite.setTextureRect(sf::IntRect(2 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
            return sprite;
            break;

        default:
            break;
        }
        return sprite;

    }







    void loadPieces(sf::Sprite (&f)[32], int (&board)[8][8], FigureTexture figures) {
        int k = 0;
        int c = 0;
        for (size_t i = 0; i < 8; i++) {
            for (size_t j = 0; j < 8; j++) {
                c = board[i][j];
                if (c) {
                    switch (c) {
                    case 6:
                        f[k] = figures.getFigureSprite(W_PAWN);
                        break;

                    case 5:
                        f[k] = figures.getFigureSprite(W_ROOK);
                        break;

                    case 4:
                        f[k] = figures.getFigureSprite(W_KNIGHT);
                        break;

                    case 3:
                        f[k] = figures.getFigureSprite(W_BISHOP);
                        break;

                    case 2:
                        f[k] = figures.getFigureSprite(W_QUEEN);
                        break;

                    case 1:
                        f[k] = figures.getFigureSprite(W_KING);
                        break;

                    case -6:
                        f[k] = figures.getFigureSprite(B_PAWN);
                        break;

                    case -5:
                        f[k] = figures.getFigureSprite(B_ROOK);
                        break;

                    case -4:
                        f[k] = figures.getFigureSprite(B_KNIGHT);
                        break;

                    case -3:
                        f[k] = figures.getFigureSprite(B_BISHOP);
                        break;

                    case -2:
                        f[k] = figures.getFigureSprite(B_QUEEN);
                        break;

                    case -1:
                        f[k] = figures.getFigureSprite(B_KING);
                        break;

                    default:
                        break;
                    }
                    f[k].setPosition(size * j, size * i);
                    k++;
                }
            }
        }

    }
}  // namespace Chess

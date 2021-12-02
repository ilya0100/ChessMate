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

        switch (fn) {
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

    void Figures::SetFiguresToDefaultPositions(Figures (&f)[32]) {
        int k = 0;
        for (int i = 0; i < 5; i++) {
            //printf("%d\n", i);
            /*
            for (int j = 0; j < 5; j++) {
                //printf("%d\n", j);
                if (board[i][j] != EMPTY_CELL) {
                    f[k].getFigureSprite(FigureTexture::board[i][j]);
                    k++;
                }
            }*/
        }

        f[10].sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
        //f[0].sprite.setPosition(size * 5, size * 5);
        f[10].sprite.setPosition(size * 1, size * 1);



        /*
        f[1].sprite.setPosition(size * 0, size * 1);
        f[2].sprite.setPosition(size * 0, size * 2);
        f[3].sprite.setPosition(size * 0, size * 3);
        f[4].sprite.setPosition(size * 0, size * 4);
        f[5].sprite.setPosition(size * 0, size * 5);
        f[6].sprite.setPosition(size * 0, size * 6);
        f[7].sprite.setPosition(size * 0, size * 7);
        f[8].sprite.setPosition(size * 1, size * 0);
        f[9].sprite.setPosition(size * 1, size * 1);
        f[10].sprite.setPosition(size * 1, size * 2);
        f[11].sprite.setPosition(size * 1, size * 3);

        f[12].sprite.setPosition(size * 1, size * 4);
        f[13].sprite.setPosition(size * 1, size * 5);
        f[14].sprite.setPosition(size * 1, size * 6);
        f[15].sprite.setPosition(size * 1, size * 7);
        f[16].sprite.setPosition(size * 2, size * 0);
        f[17].sprite.setPosition(size * 2, size * 1);
        f[18].sprite.setPosition(size * 2, size * 2);
        f[19].sprite.setPosition(size * 2, size * 3);
        //f[20].sprite.setPosition(size * 2, size * 4);
        f[21].sprite.setPosition(size * 2, size * 5);
        f[22].sprite.setPosition(size * 2, size * 6);
        f[23].sprite.setPosition(size * 2, size * 6);
        f[24].sprite.setPosition(size * 3, size * 0);
        f[25].sprite.setPosition(size * 3, size * 1);
        f[26].sprite.setPosition(size * 3, size * 2);
        f[27].sprite.setPosition(size * 3, size * 3);
        f[28].sprite.setPosition(size * 3, size * 4);
        f[29].sprite.setPosition(size * 3, size * 5);
        f[30].sprite.setPosition(size * 3, size * 6);
        f[31].sprite.setPosition(size * 3, size * 7);
        */
    }

    void Figures::DrawFigures(Figures (&f)[32], sf::RenderWindow (&window)) {
        SetFiguresToDefaultPositions(f);

        window.draw(f[10].sprite);
        window.display();

        /*for (size_t i = 0; i < 32; i++) {
            window.draw(f[i].sprite);
        }*/
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

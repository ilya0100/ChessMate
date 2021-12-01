#include "textures.hpp"

sf::Texture Chess::FigureTexture::textureN;
namespace Chess {

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
        texture.loadFromFile(texture_file);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(5, 1, SPRITE_SIZE, SPRITE_SIZE));
    }

    FigureTexture::FigureTexture() {

        // эта строка не работает, переменная статическая
        FigureTexture::textureN.loadFromFile("images/piecesT.png");

    }

    Figures::Figures(figureName fn) {
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

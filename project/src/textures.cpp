#include "textures.hpp"

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

    sf::Sprite FigureTexture::getWPawnSprite() {
        sprite.setTextureRect(sf::IntRect(5 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBPawnSprite() {
        sprite.setTextureRect(sf::IntRect(5 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    // Rook
    sf::Sprite FigureTexture::getWRookSprite() {
        sprite.setTextureRect(sf::IntRect(4 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBRookSprite() {
        sprite.setTextureRect(sf::IntRect(4 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    // Knight
    sf::Sprite FigureTexture::getWKnightSprite() {
        sprite.setTextureRect(sf::IntRect(3 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBKnightSprite() {
        sprite.setTextureRect(sf::IntRect(3 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    // Elephant
    sf::Sprite FigureTexture::getWElephantSprite() {
        sprite.setTextureRect(sf::IntRect(2 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBElephantSprite() {
        sprite.setTextureRect(sf::IntRect(2 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    // Queen
    sf::Sprite FigureTexture::getWQueenSprite() {
        sprite.setTextureRect(sf::IntRect(1 * SPRITE_SIZE, 0, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBQueenSprite() {
        sprite.setTextureRect(sf::IntRect(1 * SPRITE_SIZE, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    // King
    sf::Sprite FigureTexture::getWKingSprite() {
        sprite.setTextureRect(sf::IntRect(0, 0, SPRITE_SIZE, SPRITE_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBKingSprite() {
        sprite.setTextureRect(sf::IntRect(0, 1 * SPRITE_SIZE, SPRITE_SIZE, SPRITE_SIZE));
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
                    f[k] = figures.getWPawnSprite();
                    break;

                case 5:
                    f[k] = figures.getWRookSprite();
                    break;

                case 4:
                    f[k] = figures.getWKnightSprite();
                    break;

                case 3:
                    f[k] = figures.getWElephantSprite();
                    break;

                case 2:
                    f[k] = figures.getWQueenSprite();
                    break;

                case 1:
                    f[k] = figures.getWKingSprite();
                    break;

                case -6:
                    f[k] = figures.getBPawnSprite();
                    break;

                case -5:
                    f[k] = figures.getBRookSprite();
                    break;

                case -4:
                    f[k] = figures.getBKnightSprite();
                    break;

                case -3:
                    f[k] = figures.getBElephantSprite();
                    break;

                case -2:
                    f[k] = figures.getBQueenSprite();
                    break;

                case -1:
                    f[k] = figures.getBKingSprite();
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

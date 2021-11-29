#include "textures.hpp"

namespace Chess {

    BoardTexture::BoardTexture(const std::string filename) {
        texture.loadFromFile(filename, sf::IntRect(0, 0, 2400, 2400));
        sprite.setTexture(texture);
    }

    sf::Sprite BoardTexture::get_sprite() {
        return sprite;
    }

    void BoardTexture::getBoardPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

    void BoardTexture::setScaleBoard(float scale) {
        sprite.setScale(scale, scale);
    }

    void FigureTexture::setScaleFigure(float scale) {
        sprite.setScale(scale, scale);
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
}  // namespace Chess

#include "figures.hpp"

namespace Chess {

    FigureTexture::FigureTexture(std::string texture_file) {
        texture.loadFromFile(texture_file);
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(5, 1, CELL_SIZE, CELL_SIZE));
    }

    // Pawn
    sf::Sprite FigureTexture::getWPawnSprite() {
        sprite.setTextureRect(sf::IntRect(5 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBPawnSprite() {
        sprite.setTextureRect(sf::IntRect(5 * CELL_SIZE, 1 * CELL_SIZE, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    // Rook
    sf::Sprite FigureTexture::getWRookSprite() {
        sprite.setTextureRect(sf::IntRect(4 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBRookSprite() {
        sprite.setTextureRect(sf::IntRect(4 * CELL_SIZE, 1 * CELL_SIZE, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    // Knight
    sf::Sprite FigureTexture::getWKnightSprite() {
        sprite.setTextureRect(sf::IntRect(3 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBKnightSprite() {
        sprite.setTextureRect(sf::IntRect(3 * CELL_SIZE, 1 * CELL_SIZE, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    // Elephant
    sf::Sprite FigureTexture::getWElephantSprite() {
        sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBElephantSprite() {
        sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, 1 * CELL_SIZE, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    // Queen
    sf::Sprite FigureTexture::getWQueenSprite() {
        sprite.setTextureRect(sf::IntRect(1 * CELL_SIZE, 0, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBQueenSprite() {
        sprite.setTextureRect(sf::IntRect(1 * CELL_SIZE, 1 * CELL_SIZE, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    // King
    sf::Sprite FigureTexture::getWKingSprite() {
        sprite.setTextureRect(sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

    sf::Sprite FigureTexture::getBKingSprite() {
        sprite.setTextureRect(sf::IntRect(0, 1 * CELL_SIZE, CELL_SIZE, CELL_SIZE));
        return sprite;
    }

/*
    Pawn::Pawn() {
        w_sprite.setTexture(texture);
        w_sprite.setTextureRect(sf::IntRect(5, 0, CELL_SIZE, CELL_SIZE));
        b_sprite.setTexture(texture);
        b_sprite.setTextureRect(sf::IntRect(5, 1, CELL_SIZE, CELL_SIZE));
    }

    sf::Sprite Pawn::getWPawnSprite() const { return w_sprite; }
    sf::Sprite Pawn::getBPawnSprite() const { return b_sprite; }


    Rook::Rook() {
        w_sprite.setTexture(texture);
        w_sprite.setTextureRect(sf::IntRect(4, 0, CELL_SIZE, CELL_SIZE));
        b_sprite.setTexture(texture);
        b_sprite.setTextureRect(sf::IntRect(4, 1, CELL_SIZE, CELL_SIZE));
    }

    sf::Sprite Rook::getWRookSprite() const { return w_sprite; }
    sf::Sprite Rook::getBRookSprite() const { return b_sprite; }


    Knight::Knight() {
        w_sprite.setTexture(texture);
        w_sprite.setTextureRect(sf::IntRect(3, 0, CELL_SIZE, CELL_SIZE));
        b_sprite.setTexture(texture);
        b_sprite.setTextureRect(sf::IntRect(3, 1, CELL_SIZE, CELL_SIZE));
    }

    sf::Sprite Knight::getWKnightSprite() const { return w_sprite; }
    sf::Sprite Knight::getBKnightSprite() const { return b_sprite; }


    Elephant::Elephant() {
        w_sprite.setTexture(texture);
        w_sprite.setTextureRect(sf::IntRect(2, 0, CELL_SIZE, CELL_SIZE));
        b_sprite.setTexture(texture);
        b_sprite.setTextureRect(sf::IntRect(2, 1, CELL_SIZE, CELL_SIZE));
    }

    sf::Sprite Elephant::getWElephantSprite() const { return w_sprite; }
    sf::Sprite Elephant::getBElephantSprite() const { return b_sprite; }


    Queen::Queen() {
        w_sprite.setTexture(texture);
        w_sprite.setTextureRect(sf::IntRect(1, 0, CELL_SIZE, CELL_SIZE));
        b_sprite.setTexture(texture);
        b_sprite.setTextureRect(sf::IntRect(1, 1, CELL_SIZE, CELL_SIZE));
    }

    sf::Sprite Queen::getWQueenSprite() const { return w_sprite; }
    sf::Sprite Queen::getBQueenSprite() const { return b_sprite; }


    King::King() {
        w_sprite.setTexture(texture);
        w_sprite.setTextureRect(sf::IntRect(5, 0, CELL_SIZE, CELL_SIZE));
        b_sprite.setTexture(texture);
        b_sprite.setTextureRect(sf::IntRect(5, 1, CELL_SIZE, CELL_SIZE));
    }

    sf::Sprite King::getWKingSprite() const { return w_sprite; }
    sf::Sprite King::getBKingSprite() const { return b_sprite; }
*/
}
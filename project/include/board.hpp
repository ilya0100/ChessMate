#include <SFML/Graphics.hpp>
#include <string>
#include "utils.hpp"

namespace Chess {

    class Board {
        sf::Texture texture;
        sf::Sprite sprite;

    public:

        Board(const std::string filename);
        void PutAllFiguresOnBoard();




        // void set_texture();
        // void set_sprite();
        // sf::Texture get_texture();
        sf::Sprite get_sprite();
    };
}
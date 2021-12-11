#pragma once

#include "textures.hpp"
#include "logic.hpp"
#include "utils.hpp"

namespace Chess {
    void gamePlay(sf::RenderWindow& window, sf::Event event, Chess::BoardLogic& board_logic, Chess::Figures* figures_arr, sf::Vector2i& playSpace, sf::Vector2i& pos, size_t& n);

    void drawGame(sf::RenderWindow& window);
}

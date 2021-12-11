#include "utils.hpp"


// detect number of current cage
sf::Vector2u getCurrCage(sf::Vector2i pos, sf::Vector2i playSpace) {
    sf::Vector2u cage;
    cage.x = (pos.x - playSpace.x) / (CELL_SIZE);
    cage.y = (pos.y - playSpace.y) / (CELL_SIZE);
    return cage;
}
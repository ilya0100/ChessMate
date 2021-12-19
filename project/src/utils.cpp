#include "utils.hpp"


// detect number of current cage
sf::Vector2u getCurrCage(sf::Vector2i pos /*sf::Vector2i playSpace*/) {
    sf::Vector2u cage;
    cage.x = (pos.x - X_PLAYSPACE) / (CELL_SIZE);
    cage.y = (pos.y - Y_PLAYSPACE) / (CELL_SIZE);
    return cage;
}


sf::Vector2u Window::getSizeNew() {
	SizeNew = getSize();
	return SizeNew;
}

sf::Vector2f Window::getRatio() {
	Ratio.x = ((float)SizeNew.x) / ((float)Size.x);
	Ratio.y = ((float)SizeNew.y) / ((float)Size.y);
	return Ratio;
}

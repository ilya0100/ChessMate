#include "utils.hpp"


// detect number of current cage
sf::Vector2u getCurrCage(sf::Vector2i pos, sf::Vector2i playSpace) {
    sf::Vector2u cage;
    cage.x = (pos.x - playSpace.x) / (CELL_SIZE);
    cage.y = (pos.y - playSpace.y) / (CELL_SIZE);
    return cage;
}

Window::Window(sf::VideoMode Mode, std::string s) {
	window = new sf::RenderWindow(Mode, s);
	windowSize = window->getSize();
	windowSizeNew = window->getSize();
	windowRatio.x = (float)windowSizeNew.x/(float)windowSize.x;
	windowRatio.y = (float)windowSizeNew.x/(float)windowSize.y;
}

sf::Vector2u Window:: getWindowSize() {
	return windowSize;
}

sf::Vector2u Window:: getWindowSizeNew() {
	return windowSizeNew;
}

sf::Vector2f Window:: getWindowRatio() {
	windowRatio.x = (float)windowSizeNew.x/(float)windowSize.x;
    windowRatio.y = (float)windowSizeNew.y/(float)windowSize.y;
	return windowRatio;
}

sf::RenderWindow* Window:: getWindow() {
	return window;
}

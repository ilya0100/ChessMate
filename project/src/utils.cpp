#include "utils.hpp"

	float settings::scale_factor = 0.5;
	float settings::cell_size = settings::sprite_size * settings::scale_factor;
	float settings::sprite_size = 264;
	float settings::x_board_size = 2400;
	float settings::y_board_size = 2400;
	float settings::x_playspace = 144 * settings::scale_factor;
	float settings::y_playspace = 144 * settings::scale_factor;
	float settings::x_scale_w = 2;
	float settings::y_scale_w = 1.3;
	float settings::x_window = settings::x_board_size * settings::scale_factor * settings::x_scale_w;
	float settings::y_window = settings::y_board_size * settings::scale_factor * settings::y_scale_w;
	float settings::tsprite_size = settings::sprite_size * settings::scale_factor;







// detect number of current cage
sf::Vector2u getCurrCage(sf::Vector2i pos /*sf::Vector2i playSpace*/) {
    sf::Vector2u cage;
    cage.x = (pos.x - settings::getPsX() ) / (settings::getCs());
    cage.y = (pos.y - settings::getPsY() ) / (settings::getCs());
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




#include "menu.hpp"


int main() {

    float scale = 0.2;
    std::ifstream in("./settings/screenSize.dat");
    if (in.is_open())
        in >> scale;
    settings::scale_factor = scale;

    Window window(sf::VideoMode(settings::x_window * settings::scale_factor, settings::y_window * settings::scale_factor), "ChessMate!");

    // sf::Clock clock;
    // int menuNum = 0;

    Chess::startMenu(window);

    return 0;
}

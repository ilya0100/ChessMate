#include "menu.hpp"


int main() {

    float scale = 0.2;
    std::ifstream in("./settings/screenSize.dat");
    if (in.is_open())
        in >> scale;
    settings::scale_factor = scale;

    Window window(sf::VideoMode(settings::getXw(), settings::getYw()), "ChessMate!");

    // sf::Clock clock;
    // int menuNum = 0;

    Chess::startMenu(window);

    return 0;
}

#include "menu.hpp"



int main() {

    Window window(sf::VideoMode(X_WINDOW, Y_WINDOW), "ChessMate!");

    // sf::Clock clock;
    // int menuNum = 0;

    Chess::startMenu(window);

    return 0;
}

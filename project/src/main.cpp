#include "menu.hpp"


float arr[2] = {1, 1};
int main() {

    float arr[2] = {1, 1};
    std::ifstream in("./settings/screenSize.dat");
    if (in.is_open()) {
        in >> arr[0];
        in >> arr[1];
    }
    std::cout << arr[0] << "\n" << arr[1]<<std::endl;
    Window window(sf::VideoMode(X_WINDOW * arr[0], Y_WINDOW * arr[1]), "ChessMate!");

    // sf::Clock clock;
    // int menuNum = 0;

    Chess::startMenu(window);

    return 0;
}

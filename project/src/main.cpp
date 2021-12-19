#include "menu.hpp"



int main() {

    Window window(sf::VideoMode(X_WINDOW, Y_WINDOW), "ChessMate!");

    // sf::Clock clock;
    // int menuNum = 0;

    Chess::startMenu(window);

    // // button exit through class Button
    // Chess::Button exitBut("images/exit.png");
    // exitBut.setSize(X_EXIT, Y_EXIT);
    // exitBut.setPosition(X_WINDOW - 200, Y_WINDOW - 100);
    // // exitBut.getSprite().setPosition(X_WINDOW - 200, Y_WINDOW - 100);
    // sf::Vector2f exitPos = exitBut.getSprite().getPosition();
    // 
    // // кнопка назад
    // Chess::Button backBut("images/back.png");
    // backBut.setSize(X_BACK, Y_BACK);
    // backBut.setPosition(100, Y_WINDOW - 100);
    // sf::Vector2f backPos = backBut.getSprite().getPosition();
    // 
    // // add board and figure
    // float scale = SCALE_FACTOR;
    // Chess::BoardTexture board_texture("images/boardTru.jpg");
    // Chess::FigureTexture figures_testure;
    // board_texture.setBoardScale(SCALE_FACTOR);
    // 
    // sf::Vector2i playSpace;
    // playSpace.x = X_PLAYSPACE;
    // playSpace.y = Y_PLAYSPACE;
    // board_texture.setPlaySpace(playSpace);
    ////////////////Legacy////////////////////////////////////////////////////////

    // std::cout << "one player    " << flags.isOnePlayerMode << std::endl;
    // std::cout << "online    " << flags.isOnlineGame << std::endl;
    // std::cout << "host  " << flags.isHost << std::endl;
    // std::cout << "client    " << flags.isClient << std::endl;

    /*
    while (window.isOpen()) {
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time/120;


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // берем новый размер окна, чтобы можно было задать новую рабочую зону для кнопок
            if (event.type == sf::Event::Resized) {
				window.getSizeNew();
		 	}

            menuNum = 0;
            exitBut.getSprite().setColor(sf::Color::White);
            backBut.getSprite().setColor(sf::Color::White);
            // изначальноо соотношение размеров оконо 1:1, но после ресайза это отношение меняется, и мы по-прежнему можем нажимать на кнопки в зоне их расположения
            if (sf::IntRect(exitBut.getPosition().x * window.getRatio().x, exitBut.getPosition().y * window.getRatio().y, exitBut.getSize().x * window.getRatio().x, exitBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { exitBut.getSprite().setColor(sf::Color::Blue);menuNum = 1;}
            if (sf::IntRect(backBut.getPosition().x * window.getRatio().x, backBut.getPosition().y * window.getRatio().y, backBut.getSize().x * window.getRatio().x, backBut.getSize().y * window.getRatio().y).contains(sf::Mouse::getPosition(window))) { backBut.getSprite().setColor(sf::Color::Blue);menuNum = 2;}
            // if (sf::IntRect(pos.x * windowRatio.x, pos.y * windowRatio.y, (float)backSize.x * windowRatio.x, (float)backSize.y * windowRatio.y).contains(sf::Mouse::getPosition(window))) {}

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                Chess::startMenu(window, flags);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (menuNum == 1) {
                    window.close();
                }
                if (menuNum == 2)  {
                    flags.isClient = false;
                    flags.isHost = false;
                    flags.isOnePlayerMode = false;
                    Chess::selectMode(window, flags); }
            }

            gameplay.play(event, pos); // proveryaet hod
        }

        window.clear();
        //window.draw(menu_texture.getSprite());
        window.clear(sf::Color(129, 181, 221));
        window.draw(board_texture.getSprite());
        window.draw(exitBut.getSprite());
        window.draw(backBut.getSprite());

        gameplay.updateSprites();
        gameplay.drawFigures(window, pos);

        window.display();

        gameplay.recieveBoardState();
    }
    */

    return 0;
}

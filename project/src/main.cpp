#include "textures.hpp"
#include "logic.hpp"
#include "utils.hpp"
#include "menu.hpp"

// detect number of current cage
sf::Vector2u getCurrCage(sf::Vector2i pos, sf::Vector2i playSpace) {
    sf::Vector2u cage;
    cage.x = (pos.x - playSpace.x) / (CELL_SIZE);
    cage.y = (pos.y - playSpace.y) / (CELL_SIZE);
    return cage;
}


int main() {

    sf::Clock clock;
    int menuNum = 0;
    sf::RenderWindow window(sf::VideoMode(X_WINDOW, Y_WINDOW), "ChessMate!");
    Chess::menu(window);

    // размер окна для сохранения работоспособности при изменении размера
    sf::Vector2u windowSize = window.getSize();
	sf::Vector2u windowSizeNew = window.getSize();
    sf::Vector2f windowRatio;
    windowRatio.x = (float)windowSizeNew.x/(float)windowSize.x;
    windowRatio.y = (float)windowSizeNew.y/(float)windowSize.y;

    // button exit through class Button
    Chess::Button exitButton("images/exit.png");
    exitButton.setSize(X_EXIT, Y_EXIT);
    exitButton.getSprite().setPosition(X_WINDOW - 200, Y_WINDOW - 100);
    // exitButton.getSprite().setPosition(X_WINDOW - 200, Y_WINDOW - 100);
    sf::Vector2f exitPos = exitButton.getSprite().getPosition();

    // кнопка выхода
    //    sf::Texture ExitTexture;
    //    ExitTexture.loadFromFile("images/exit.png");
    //    sf::Sprite exit(ExitTexture);
    //    exit.setPosition(X_WINDOW - 200, Y_WINDOW - 100);
    //    sf::Vector2u exitSize;
	//    exitSize.x = 119;
	//    exitSize.y = 43;
	//    sf::Vector2f exitPos = exit.getPosition();

    // кнопка назад
    Chess::Button backButton("images/back.png");
    backButton.setSize(X_BACK, Y_BACK);
    backButton.getSprite().setPosition(100, Y_WINDOW - 100);
    sf::Vector2f backPos = backButton.getSprite().getPosition();

    // sf::Texture BackTexture;
    // BackTexture.loadFromFile("images/back.png");
    // sf::Sprite back(BackTexture);
    // back.setPosition(100, Y_WINDOW - 100);
    // sf::Vector2u backSize;
	// backSize.x = 284;
	// backSize.y = 53;
	// sf::Vector2f backPos = back.getPosition();

    // add board and figure 
    float scale = SCALE_FACTOR;
    Chess::BoardTexture board_texture("images/boardTru.jpg");
    Chess::FigureTexture figures_testure;
    board_texture.setBoardScale(SCALE_FACTOR);
    
    Chess::BoardLogic board_logic;
    Chess::Figures figures_arr[32];

    sf::Vector2i playSpace;
    playSpace.x = X_PLAYSPACE;
    playSpace.y = Y_PLAYSPACE;
    board_texture.setPlaySpace(playSpace);

/*
    //////////////////////////Netcode/////////////////////////////////////
    sf::TcpSocket socket;
    sf::IpAddress ip = sf::IpAddress::getLocalAddress();

    char type;

    std::cout << "Enter type connecting: [c] - client, [s] - server\n";
    std::cin  >> type;

    if (type == 's') {
        ReuseableListener listener;
        listener.listen(8080);
        listener.reuse();

        if(listener.accept(socket) != sf::Socket::Done) {
            std::cout << "Error!\n";
        }
    }
    else if (type == 'c') {
        if (socket.connect(ip, 8080) != sf::Socket::Done) {
            std::cout << "Error!\n";
        }
    }

    socket.setBlocking(true);

    sf::Packet packet;

    if (type == 'c') {
        if(socket.receive(packet) == sf::Socket::Done) {
            packet >> board_logic;
        }
    } 
    ////////////////////////////////////////////////////////////////////////////
*/

    int k = 0;
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            figureName figure = board_logic(x, y);

            if (figure != EMPTY_CELL && k < 32) {
                Chess::loadPieces(figures_arr[k], figure, x, y);
                k++;
            }
        }
    }

    sf::Vector2u curr_cage;
    bool isMove = false;
    bool isCatch = false;
    float dx = 0;
    float dy = 0;
    size_t n = 0;
    int eaten_count = 0;


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
				windowSizeNew = window.getSize();
                windowRatio.x = (float)windowSizeNew.x/(float)windowSize.x;
                windowRatio.y = (float)windowSizeNew.y/(float)windowSize.y;
		 	}

            menuNum = 0;
            exitButton.getSprite().setColor(sf::Color::White);
            backButton.getSprite().setColor(sf::Color::White);
            // изначальноо соотношение размеров оконо 1:1, но после ресайза это отношение меняется, и мы по-прежнему можем нажимать на кнопки в зоне их расположения
            if (sf::IntRect(exitPos.x * windowRatio.x, exitPos.y * windowRatio.y, (float)exitButton.getSize().x * windowRatio.x, (float)exitButton.getSize().y * windowRatio.y).contains(sf::Mouse::getPosition(window))) { exitButton.getSprite().setColor(sf::Color::Blue); menuNum = 3; }
            if (sf::IntRect(backPos.x * windowRatio.x, backPos.y * windowRatio.y, (float)backButton.getSize().x * windowRatio.x, (float)backButton.getSize().y * windowRatio.y).contains(sf::Mouse::getPosition(window))) { backButton.getSprite().setColor(sf::Color::Blue); menuNum = 4; }
            // if (sf::IntRect(pos.x * windowRatio.x, pos.y * windowRatio.y, (float)backSize.x * windowRatio.x, (float)backSize.y * windowRatio.y).contains(sf::Mouse::getPosition(window))) {}

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                Chess::menu(window);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (menuNum == 3)  { window.close(); }
                if (menuNum == 4)  { Chess::menu(window); }
            }

            //drag and drop
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    for (size_t i = 0; i < 32; i++) {
                        if (figures_arr[i].getFigureSprite().getGlobalBounds().contains(pos.x, pos.y)) {
                            if (board_logic.cur_side == figures_arr[i].getSide()) {
                            isCatch = true;
                            isMove = true;
                            curr_cage = getCurrCage(pos, playSpace);
                            board_logic.setFigurePosition(curr_cage);
                            n = i;
                            }
                        }
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (event.key.code == sf::Mouse::Left) {
                    isMove = false;

                    if (isCatch) {
                        curr_cage = getCurrCage(pos, playSpace);
                        
                        if (board_logic.isMoveFigure(curr_cage.x, curr_cage.y)) {
                            if (board_logic(curr_cage.x, curr_cage.y) != EMPTY_CELL) {
                                for (size_t i = 0; i < 32; i++) {
                                    if (figures_arr[i].getFigurePos() == curr_cage) {
                                        figures_arr[i].setSpritePos(600 + TSPRITE_SIZE * eaten_count, 100);
                                        eaten_count++;
                                        break;
                                    }
                                }

                            if (board_logic.cur_side == BLACK) {
                                board_logic.cur_side = WHITE;
                            }
                            else if (board_logic.cur_side == WHITE) {
                                board_logic.cur_side = BLACK;
                            }
                            }

                            figures_arr[n].setFigurePos(curr_cage.x, curr_cage.y);

                            // packet << board_logic;
                            // socket.send(packet);
                            // if(socket.receive(packet) == sf::Socket::Done) {
                            //     packet >> board_logic;
                            // }
                            
                        } else {
                            curr_cage = board_logic.getFigurePosition();
                            figures_arr[n].setFigurePos(curr_cage.x, curr_cage.y);
                        }
                        isCatch = false;
                    }
                }
            }

        }

        window.clear();
        //window.draw(menu_texture.getSprite());
        window.clear(sf::Color(129, 181, 221));
        window.draw(board_texture.getSprite());
        window.draw(exitButton.getSprite());
        window.draw(backButton.getSprite());

        /*
        k = 0;
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                figureName figure = board_logic(x, y);
    
                if (figure != EMPTY_CELL && k < 32) {
                    Chess::loadPieces(figures_arr[k], figure, x, y);
                    k++;
                }
            }
        }
        */

        for (size_t i = 0; i < 32; i++) {
            if (isMove && i == n) {
                figures_arr[i].moveFigure(pos.x - TSPRITE_SIZE / 2, pos.y - TSPRITE_SIZE / 2);
            }
            window.draw(figures_arr[i].getFigureSprite());
        }

        window.display();
    }

    return 0;
}

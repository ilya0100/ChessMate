#include "gameplay.hpp"
#include "menu.hpp"



int main() {
    Flags flags;
    Window window(sf::VideoMode(X_WINDOW, Y_WINDOW), "ChessMate!");

    sf::Clock clock;
    int menuNum = 0;

    Chess::startMenu(window, flags);




    // button exit through class Button
    Chess::Button exitBut("images/exit.png");
    exitBut.setSize(X_EXIT, Y_EXIT);
    exitBut.setPosition(X_WINDOW - 200, Y_WINDOW - 100);
    // exitBut.getSprite().setPosition(X_WINDOW - 200, Y_WINDOW - 100);
    sf::Vector2f exitPos = exitBut.getSprite().getPosition();

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
    Chess::Button backBut("images/back.png");
    backBut.setSize(X_BACK, Y_BACK);
    backBut.setPosition(100, Y_WINDOW - 100);
    sf::Vector2f backPos = backBut.getSprite().getPosition();

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

    // Chess::BoardLogic board_logic;
    // Chess::Figures figures_arr[32];

    sf::Vector2i playSpace;
    playSpace.x = X_PLAYSPACE;
    playSpace.y = Y_PLAYSPACE;
    board_texture.setPlaySpace(playSpace);


    //////////////////////////Netcode/////////////////////////////////////
    // sf::TcpSocket socket;
    // sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    // 
    // SocAndIP socIP;
    // socIP.ip = sf::IpAddress::getLocalAddress();
    // 
    // char type;
    // 
    // std::cout << "Enter type connecting: [c] - client, [s] - server\n";
    // std::cin  >> type;
    // 
    // if (flags.isHost) {
    //     ReuseableListener listener;
    //     listener.listen(8080);
    //     listener.reuse();
    // 
    //     if(listener.accept(socIP.socket) != sf::Socket::Done) {
    //         std::cout << "Error!\n";
    //     }
    // }
    // else if (flags.isClient) {
    //     if (socIP.socket.connect(socIP.ip, 8080) != sf::Socket::Done) {
    //         std::cout << "Error!\n";
    //     }
    // }
    // 
    // socIP.socket.setBlocking(true);
    // 
    // sf::Packet packet;
    // 
    // bool enemy_turn = false;
    // if (flags.isClient) {
    //     enemy_turn = true;
    //     board_logic.setSide(BLACK);
    // } else {
    //     board_logic.setSide(WHITE);
    // }
    ////////////////////////////////////////////////////////////////////////////


    // int k = 0;
    // for (int y = 0; y < 8; y++) {
    //     for (int x = 0; x < 8; x++) {
    //         figureName figure = board_logic(x, y);
    // 
    //         if (figure != EMPTY_CELL && k < 32) {
    //             Chess::loadPieces(figures_arr[k], figure, x, y);
    //             k++;
    //         }
    //     }
    // }
    //
    // sf::Vector2u curr_cage;
    // bool isMove = false;
    // bool isCatch = false;
    // float dx = 0;
    // float dy = 0;
    // size_t fig_num = 0;
    // int eaten_count = 0;
    //////////////////Legacy///////////////////////////////////////////

    std::cout << "one player    " << flags.isOnePlayerMode << std::endl;
    std::cout << "online    " << flags.isOnlineGame << std::endl;
    std::cout << "host  " << flags.isHost << std::endl;
    std::cout << "client    " << flags.isClient << std::endl;

    Chess::Gameplay gameplay;
    gameplay.setSide();
    if (flags.isHost) {
        gameplay.setGameMode(HOST);
    } else if (flags.isClient) {
        gameplay.setGameMode(CLIENT);
        gameplay.setSide(BLACK);
    }
    gameplay.updateSprites();

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

            gameplay.play(event, pos);
            
            // //drag and drop
            // if (event.type == sf::Event::MouseButtonPressed) {
            //     if (event.key.code == sf::Mouse::Left) {
            //         for (size_t i = 0; i < 32; i++) {
            //             if (figures_arr[i].getFigureSprite().getGlobalBounds().contains(pos.x, pos.y)) {
            //                 if (board_logic.cur_side == figures_arr[i].getSide()) {
            //                     isCatch = true;
            //                     isMove = true;
            //                     curr_cage = getCurrCage(pos, playSpace);
            //                     board_logic.setFigurePosition(curr_cage);
            //                     fig_num = i;
            //                 }
            //             }
            //         }
            //     }
            // }
            // 
            // if (event.type == sf::Event::MouseButtonReleased) {
            //     if (event.key.code == sf::Mouse::Left) {
            //         isMove = false;
            // 
            //         if (isCatch) {
            //             curr_cage = getCurrCage(pos, playSpace);
            //             
            //             if (board_logic.isMoveFigure(curr_cage.x, curr_cage.y)) {
            //                 if (board_logic(curr_cage.x, curr_cage.y) != EMPTY_CELL) {
            //                     // for (size_t i = 0; i < 32; i++) {
            //                     //     if (figures_arr[i].getFigurePos() == curr_cage) {
            //                     //         figures_arr[i].setSpritePos(600 + TSPRITE_SIZE * eaten_count, 100);
            //                     //         eaten_count++;
            //                     //         break;
            //                     //     }
            //                     // }
            //                 }
            //                 figures_arr[fig_num].setFigurePos(curr_cage.x, curr_cage.y);
            // 
            //                 if (flags.isOnePlayerMode) {
            //                     board_logic.upsideDown();
            //                 }
            // 
            //                 if (board_logic.cur_side == BLACK) {
            //                     board_logic.cur_side = WHITE;
            //                 } else if (board_logic.cur_side == WHITE) {
            //                     board_logic.cur_side = BLACK;
            //                 }
            // 
            //                 if (flags.isOnlineGame) {
            //                     packet << board_logic;
            //                     socIP.socket.send(packet);
            //                     packet.clear();
            //                     enemy_turn = true;
            //                 }
            //                 
            //             } else {
            //                 curr_cage = board_logic.getFigurePosition();
            //                 figures_arr[fig_num].setFigurePos(curr_cage.x, curr_cage.y);
            //             }
            //             isCatch = false;
            //         }
            //     }
            // }
            ////////////////////////Legacy////////////////////////////////////////////////////
            
        }

        window.clear();
        //window.draw(menu_texture.getSprite());
        window.clear(sf::Color(129, 181, 221));
        window.draw(board_texture.getSprite());
        window.draw(exitBut.getSprite());
        window.draw(backBut.getSprite());

        gameplay.updateSprites();
        gameplay.drawFigures(window, pos);
        
        // k = 0;
        // for (int y = 0; y < 8; y++) {
        //     for (int x = 0; x < 8; x++) {
        //         figureName figure = board_logic(x, y);
        // 
        //         if (figure != EMPTY_CELL && k < 32) {
        //             Chess::loadPieces(figures_arr[k], figure, x, y);
        //             k++;
        //         }
        //     }
        // }
        // 
        // for (size_t i = 0; i < 32; i++) {
        //     if (isMove && i == fig_num) {
        //         figures_arr[i].moveFigure(pos.x - TSPRITE_SIZE / 2, pos.y - TSPRITE_SIZE / 2);
        //     }
        //     window.draw(figures_arr[i].getFigureSprite());
        // }
        //////////////////////////////Legacy//////////////////////////////////////////////////////

        window.display();

        gameplay.recieveBoardState();

        // if (enemy_turn) {
        //     if(socIP.socket.receive(packet) == sf::Socket::Done) {
        //         packet >> board_logic;
        //         packet.clear();
        //         board_logic.upsideDown();
        //         enemy_turn = false;
        // 
        //         if (board_logic.cur_side == BLACK) {
        //             board_logic.cur_side = WHITE;
        //         }
        //         else if (board_logic.cur_side == WHITE) {
        //             board_logic.cur_side = BLACK;
        //         }
        //     }
        // }
        //////////////////////////////Legacy//////////////////////////////////////////////////////
    }

    return 0;
}

#include "gameplay.hpp"

namespace Chess {

    void gamePlay(sf::RenderWindow& window) {
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
            sf::Event event;

            while (window.pollEvent(event)) {
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
            window.clear(sf::Color(129, 181, 221));
            window.draw(board_texture.getSprite());
        
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

            for (size_t i = 0; i < 32; i++) {
                if (isMove && i == n) {
                    figures_arr[i].moveFigure(pos.x - TSPRITE_SIZE / 2, pos.y - TSPRITE_SIZE / 2);
                }
                window.draw(figures_arr[i].getFigureSprite());
            }

            window.display();
        }
    }

}  // namespace Chess

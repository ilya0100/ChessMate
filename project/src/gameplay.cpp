#include "gameplay.hpp"

namespace Chess {

//////////////////////////NetWork//////////////////////////////////

    bool NetWork::host() {
        listener.listen(8080);
        listener.reuse();
    
        if(listener.accept(socket) != sf::Socket::Done) {
            std::cout << "Error!\n";
            return false;
        }
        socket.setBlocking(false);
        return true;
    }

    bool NetWork::client(std::string adress) {
        std::cout << "ip: " << adress << std::endl;
        sf::IpAddress host(adress);
        if (socket.connect(host, 8080) != sf::Socket::Done) {
            std::cout << "Error!\n";
            return false;
        }
        socket.setBlocking(false);
        return true;
    }

//////////////////////////Gameplay////////////////////////////////

    Gameplay::Gameplay() {
        updateSprites();
    }

    void Gameplay::updateSprites() {
        int k = 0;
        for (int y = 0; y < 8; y++) {
            for (int x = 0; x < 8; x++) {
                figureName figure = board[y][x];

                if (figure != EMPTY_CELL) {
                    loadPieces(figures_arr[k], figure, x, y);
                    k++;
                }
            }
        }
        fig_count = k;
    }

    void Gameplay::setGameMode(GameMode new_mode) {
        mode = new_mode;
        if (mode == CLIENT) {
            enemy_turn = true;
    	    setSide(BLACK);
        }
        // if (mode == HOST) {
        //     host();
        // } else if (mode == CLIENT) {
        //     client();
        //     enemy_turn = true;
    	//     setSide(BLACK);
        // }
        // socket.setBlocking(false);
    }

    void Gameplay::play(sf::Event event, sf::Vector2i pos) {

        //drag and drop
        if (!enemy_turn && event.type == sf::Event::MouseButtonPressed) {
            if (event.key.code == sf::Mouse::Left) {
                for (size_t i = 0; i < fig_count; i++) {
                    if (sf::IntRect(figures_arr[i].getFigureSprite().getGlobalBounds().left, figures_arr[i].getFigureSprite().getGlobalBounds().top, figures_arr[i].getFigureSprite().getGlobalBounds().width, figures_arr[i].getFigureSprite().getGlobalBounds().height).contains(pos.x, pos.y)) {

                        // std::cout << "cur_side: " << cur_side << std::endl;
                        // std::cout << "fig_side: " << figures_arr[i].getSide() << std::endl;

                        if (cur_side == figures_arr[i].getSide()) {
                            isCatch = true;
                            isMove = true;
                            curr_cage = getCurrCage(pos);
                            setFigurePosition(curr_cage);
                            fig_num = i;
                        }
                    }
                }
            }
        }

        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.key.code == sf::Mouse::Left) {
                isMove = false;

                if (isCatch) {
                    curr_cage = getCurrCage(pos);
                        
                    if (isMoveFigure(curr_cage.x, curr_cage.y) && !isCheck()) {
                        // for (size_t i = 0; i < fig_count - eaten_count; i++) {
                        //     if (figures_arr[i].getFigurePos() == curr_cage) {
                        //         // figures_arr[i].setSpritePos(600 + 2 * 3 * TSPRITE_SIZE * (eaten_count % 8), 100 * (eaten_count / 8));
                        //         eaten_count++;
                        //         break;
                        //     }
                        // }

                        if (mode == ONE_PLAYER) {
                            upsideDown();
                            changeSide();
                        }

                        sendBoardState();       
                    }
                    isCatch = false;
                }
            }
        }
    }

    void Gameplay::drawFigures(Window& window, sf::Vector2i pos) {
        for (size_t i = 0; i < fig_count - eaten_count; i++) {
            if (isMove && i == fig_num) {
                figures_arr[i].moveFigure(pos.x - TSPRITE_SIZE / 2, pos.y - TSPRITE_SIZE / 2);
            }
            if (figures_arr[i].getName() != EMPTY_CELL) {
                window.draw(figures_arr[i].getFigureSprite());
            }
        }
    }

    void Gameplay::sendBoardState() {
        if (mode == HOST || mode == CLIENT) {
            packet << *this;
            packet << previos_fig;
            for (int i = 0; i < 2; i++) {
                packet << previos_move[i].x;
                packet << previos_move[i].y;
            }
            packet << wshort_castling << wlong_castling << bshort_castling << blong_castling;

            socket.send(packet);
            packet.clear();
            enemy_turn = true;
        }
    }

    void Gameplay::recieveBoardState() {
        if (enemy_turn && (mode == HOST || mode == CLIENT)) {
            if(socket.receive(packet) == sf::Socket::Done) {
                packet >> *this;
                int buffer;
                packet >> buffer;
                previos_fig = (figureName)buffer;
                for (int i = 0; i < 2; i++) {
                    packet >> previos_move[i].x;
                    packet >> previos_move[i].y;
                }
                packet >> wshort_castling >> wlong_castling >> bshort_castling >> blong_castling;

                packet.clear();
                enemy_turn = false;
            }
        }
    }

/////////////////////////////////////////////////////////////////////////////////////

    void loadPieces(Figures& figure, figureName figure_name, size_t i, size_t j) {
        switch (figure_name) {
        case W_PAWN:
            figure.setSprite(W_PAWN);
            break;

        case W_ROOK:
            figure.setSprite(W_ROOK);
            break;

        case W_KNIGHT:
            figure.setSprite(W_KNIGHT);
            break;

        case W_BISHOP:
            figure.setSprite(W_BISHOP);
            break;

        case W_QUEEN:
            figure.setSprite(W_QUEEN);
            break;

        case W_KING:
            figure.setSprite(W_KING);
            break;

        case B_PAWN:
            figure.setSprite(B_PAWN);
            break;

        case B_ROOK:
            figure.setSprite(B_ROOK);
            break;

        case B_KNIGHT:
            figure.setSprite(B_KNIGHT);
            break;

        case B_BISHOP:
            figure.setSprite(B_BISHOP);
            break;

        case B_QUEEN:
            figure.setSprite(B_QUEEN);
            break;

        case B_KING:
            figure.setSprite(B_KING);
            break;

        // case EMPTY_CELL:
        //     return;

        default:
            break;
        }
        figure.setFigurePos(i, j);
    }

}  // namespace Chess

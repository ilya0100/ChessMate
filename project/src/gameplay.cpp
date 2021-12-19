#include "gameplay.hpp"

namespace Chess {

//////////////////////////NetWork//////////////////////////////////

    void NetWork::host() {
        listener.listen(8080);
        listener.reuse();
    
        if(listener.accept(socket) != sf::Socket::Done) {
            std::cout << "Error!\n";
        }
    }

    void NetWork::client() {
        if (socket.connect(ip, 8080) != sf::Socket::Done) {
            std::cout << "Error!\n";
        }
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

                if (figure != EMPTY_CELL && k < 32) {
                    loadPieces(figures_arr[k], figure, x, y);
                    k++;
                }
            }
        }

        // if (cur_side == BLACK) {
        //     std::cout << "update: cur_side - BLACK" << std::endl;
        // }
    }

    void Gameplay::setGameMode(GameMode new_mode) {
        mode = new_mode;
        if (mode == HOST) {
            host();
        } else if (mode == CLIENT) {
            client();
            enemy_turn = true;
        }
    }

    void Gameplay::play(sf::Event event, sf::Vector2i pos) {

        // if (cur_side == BLACK) {
        //     std::cout << "play: cur_side - BLACK" << std::endl;
        // }

        //drag and drop
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.key.code == sf::Mouse::Left) {
                for (size_t i = 0; i < 32; i++) {
                    if (figures_arr[i].getFigureSprite().getGlobalBounds().contains(pos.x, pos.y)) {

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
                        
                    if (isMoveFigure(curr_cage.x, curr_cage.y)) {
                        // if (board[curr_cage.x][curr_cage.y] != EMPTY_CELL) {
                            // for (size_t i = 0; i < 32; i++) {
                            //     if (figures_arr[i].getFigurePos() == curr_cage) {
                            //         figures_arr[i].setSpritePos(600 + TSPRITE_SIZE * eaten_count, 100);
                            //         eaten_count++;
                            //         break;
                            //     }
                            // }
                        // }
                        figures_arr[fig_num].setFigurePos(curr_cage.x, curr_cage.y);

                        if (mode == ONE_PLAYER) {
                            upsideDown();
                            changeSide();
                        }

                        sendBoardState();
                            
                    } else {
                        curr_cage = getFigurePosition();
                        figures_arr[fig_num].setFigurePos(curr_cage.x, curr_cage.y);
                    }
                    isCatch = false;
                }
            }
        }
    }

    void Gameplay::drawFigures(sf::RenderWindow& window, sf::Vector2i pos) {
        for (size_t i = 0; i < 32; i++) {
            if (isMove && i == fig_num) {
                figures_arr[i].moveFigure(pos.x - TSPRITE_SIZE / 2, pos.y - TSPRITE_SIZE / 2);
            }
            window.draw(figures_arr[i].getFigureSprite());
        }
    }

    void Gameplay::sendBoardState() {
        if (mode == HOST || mode == CLIENT) {
            for (int y = 0; y < 8; y++) {
                for (int x = 0; x < 8; x ++) {
                    packet << board[y][x];
                }
            }
            socket.send(packet);
            packet.clear();
            enemy_turn = true;

            // std::cout << "sended" << std::endl;
        }
    }

    void Gameplay::recieveBoardState() {
        if (enemy_turn && (mode == HOST || mode == CLIENT)) {
            if(socket.receive(packet) == sf::Socket::Done) {
                for (int y = 0; y < 8; y++) {
                    for (int x = 0; x < 8; x ++) {
                        int buffer;
                        packet >> buffer;
                        board[y][x] = (figureName)buffer;
                    }
                }
                packet.clear();
                enemy_turn = false;
                upsideDown();

                // std::cout << "recieved" << std::endl;
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

        default:
            break;
        }
        figure.setFigurePos(i, j);
    }

}  // namespace Chess

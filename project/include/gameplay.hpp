#pragma once

#include "textures.hpp"
#include "logic.hpp"
#include "utils.hpp"

namespace Chess {

    class NetWork {
        protected:
            sf::TcpSocket socket;
            sf::IpAddress ip = sf::IpAddress::getLocalAddress();
            ReuseableListener listener;

            sf::Packet packet;

            bool isHost = true;

        public:
            NetWork() = default;

            void host();
            void client();

            void setIP(sf::IpAddress ip);
            void getIP() const;
    };

    class Gameplay: public BoardLogic, public NetWork {
            sf::Vector2u curr_cage;
            GameMode mode = ONE_PLAYER;
            Figures figures_arr[32];

            bool isMove = false;
            bool isCatch = false;
            bool enemy_turn = false;
            
            float dx = 0;
            float dy = 0;
            size_t fig_num = 0;
            int eaten_count = 0;

            void sendBoardState();

        public:
            Gameplay();

            void recieveBoardState();
            void updateSprites();
            void setGameMode(GameMode new_mode);

            void play(sf::Event event, sf::Vector2i pos);

            void drawFigures(sf::RenderWindow& window, sf::Vector2i pos);
    };

    void loadPieces(Figures& figure, figureName figure_name, size_t i, size_t j);
}  // namespace Chess

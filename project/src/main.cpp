#include "textures.hpp"
#include "logic.hpp"
#include "utils.hpp"

#define CELL_SIZE 52


sf::Sprite f[32];

// detect number of current cage
NumCage getCurrCage(sf::Vector2i pos, sf::Vector2i playSpace) {
    NumCage cage;
    cage.x = (pos.x - playSpace.x) / CELL_SIZE;
    cage.y = (pos.y - playSpace.y) / CELL_SIZE;
    return cage;
}
  Chess::BoardLogic board_logic;
int board[8][8] =
    {{-5, -4, -3, -2, -1, -3, -4, -5},
      {-6, -6, -6, -6, -6, -6, -6, -6},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {6,  6,  6,  6,  6,  6,  6,  6},
      {5,  4,  3,  2,  1,  3,  4,  5}};



int main()
{
    //Chess::Figures F[32]; // пока тестируется
    sf::Clock clock;
    int menuNum = 0;
    sf::RenderWindow window(sf::VideoMode(590, 590), "ChessMate!");
    menu(window);

    // размер окна для сохранения работоспособности при изменении размера
    sf::Vector2u windowSize = window.getSize();
	sf::Vector2u windowSizeNew = window.getSize();
    sf::Vector2f windowRatio;
    windowRatio.x = (float)windowSizeNew.x/(float)windowSize.x;
    windowRatio.y = (float)windowSizeNew.y/(float)windowSize.y;

    // кнопка выхода
    sf::Texture ExitTexture;
    ExitTexture.loadFromFile("images/exit.png");
    sf::Sprite exit(ExitTexture);
    exit.setPosition(500, 500);
    sf::Vector2u exitSize;
	exitSize.x = 61;
	exitSize.y = 23;
	sf::Vector2f exitPos = exit.getPosition();

    //кнопка назад
    sf::Texture BackTexture;
    BackTexture.loadFromFile("images/back.png");
    sf::Sprite back(BackTexture);
    back.setPosition(38, 550);
    sf::Vector2u backSize;
	backSize.x = 133;
	backSize.y = 23;
	sf::Vector2f backPos = back.getPosition();


    Chess::BoardTexture board_texture("images/boardT.jpg");
    Chess::FigureTexture figures;

    sf::Vector2i playSpace;
    playSpace.x = 0; // correct
    playSpace.y = 0;
    board_texture.setPlaySpace(playSpace);

    //Chess::Figures::SetFiguresToDefaultPositions(F);
    Chess::loadPieces(f, board, figures);

    NumCage curr_cage = {0};
    bool isMove = false;
    bool isCatch = false;
    float dx = 0;
    float dy = 0;
    size_t n = 0;

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
            exit.setColor(sf::Color::White);
            back.setColor(sf::Color::White);
            // изначальноо соотношение размеров оконо 1:1, но после ресайза это отношение меняется, и мы по-прежнему можем нажимать на кнопки в зоне их расположения
            if (sf::IntRect(exitPos.x * windowRatio.x, exitPos.y * windowRatio.y, (float)exitSize.x * windowRatio.x, (float)exitSize.y * windowRatio.y).contains(sf::Mouse::getPosition(window))) { exit.setColor(sf::Color::Blue); menuNum = 3; }
            if (sf::IntRect(backPos.x * windowRatio.x, backPos.y * windowRatio.y, (float)backSize.x * windowRatio.x, (float)backSize.y * windowRatio.y).contains(sf::Mouse::getPosition(window))) { back.setColor(sf::Color::Blue); menuNum = 4; }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                menu(window);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (menuNum == 3)  { window.close();}
                if (menuNum == 4)  { menu(window);}
            }

            //drag and drop
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    for (size_t i = 0; i < 32; i++) {
                        if (f[i].getGlobalBounds().contains(pos.x, pos.y)) {
                            isCatch = true;
                            isMove = true;
                            curr_cage = getCurrCage(pos, playSpace); //getPlaySpace
                            board_logic.setFigurePosition(curr_cage.x, curr_cage.y);
                            n = i;
                            dx = pos.x - f[i].getPosition().x;
                            dy = pos.y - f[i].getPosition().y;
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
                            f[n].setPosition(playSpace.x + curr_cage.x * CELL_SIZE, playSpace.y + curr_cage.y * CELL_SIZE);;
                        } else {
                            curr_cage = board_logic.getFigurePosition();
                            f[n].setPosition(playSpace.x + curr_cage.x * CELL_SIZE, playSpace.y + curr_cage.y * CELL_SIZE);
                        }
                    }
                }
            }

        }

        if (isMove) { f[n].setPosition(pos.x - dx, pos.y - dy); }

        window.clear();
        //window.draw(menu_texture.get_sprite());
        window.clear(sf::Color(129, 181, 221));
        window.draw(exit);
        window.draw(back);
        window.draw(board_texture.get_sprite());

        //Chess::Figures::DrawFigures(F, window);
        /*
        for (size_t i = 0; i < 32; i++) {
            window.draw(F[i].sprite);
        }
        */

        for (size_t i = 0; i < 32; i++) {
            window.draw(f[i]);
        }
        window.display();
    }

    return 0;
}

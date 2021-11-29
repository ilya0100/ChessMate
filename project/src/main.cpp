#include "textures.hpp"
#include "logic.hpp"
#include "utils.hpp"

size_t size = 52;

sf::Sprite f[32];

// detect number of current cage
NumCage getCurrCage(sf::Vector2i pos, sf::Vector2i playSpace) {
    NumCage cage;
    cage.x = (pos.x - playSpace.x) / CELL_SIZE;
    cage.y = (pos.y - playSpace.y) / CELL_SIZE;
    return cage;
}

int board[8][8] =
    {{-5, -4, -3, -1, -2, -3, -4, -5},
     {-6, -6, -6, -6, -6, -6, -6, -6},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {6,  6,  6,  6,  6,  6,  6,  6},
      {5,  4,  3,  1,  2,  3,  4,  5}};

int main()
{   
    int menuNum = 0;
    sf::RenderWindow window(sf::VideoMode(590, 590), "ChessMate!");
    menu(window);
    sf::Texture ExitTexture;
    ExitTexture.loadFromFile("images/exit.png");
    sf::Sprite exit(ExitTexture);
    exit.setPosition(500, 500);


    Chess::BoardTexture board_texture("images/boardT.jpg");
    Chess::FigureTexture figures("images/piecesT.png");
    Chess::BoardLogic board_logic;

    sf::Vector2i playSpace;
    playSpace.x = 0; // correct
    playSpace.y = 0;
    board_texture.setPlaySpace(playSpace);

    
 

    int k = 0;
    int c = 0;
    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            c = board[i][j];
            if (c) {
                switch (c) {
                case 6:
                    f[k] = figures.getWPawnSprite();
                    break;

                case 5:
                    f[k] = figures.getWRookSprite();
                    break;

                case 4:
                    f[k] = figures.getWKnightSprite();
                    break;

                case 3:
                    f[k] = figures.getWElephantSprite();
                    break;

                case 2:
                    f[k] = figures.getWQueenSprite();
                    break;

                case 1:
                    f[k] = figures.getWKingSprite();
                    break;

                case -6:
                    f[k] = figures.getBPawnSprite();
                    break;

                case -5:
                    f[k] = figures.getBRookSprite();
                    break;

                case -4:
                    f[k] = figures.getBKnightSprite();
                    break;

                case -3:
                    f[k] = figures.getBElephantSprite();
                    break;

                case -2:
                    f[k] = figures.getBQueenSprite();
                    break;

                case -1:
                    f[k] = figures.getBKingSprite();
                    break;

                default:
                    break;
                }
                f[k].setPosition(size * j, size * i);
                k++;
            }
        }
    }

    NumCage curr_cage = {0};
    bool isMove = false;
    bool isCatch = false;
    float dx = 0;
    float dy = 0;
    size_t n = 0;

    while (window.isOpen())
    {
        sf::Vector2i pos = sf::Mouse::getPosition(window);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

        exit.setColor(sf::Color::White);
		menuNum = 0;    
        if (sf::IntRect(500, 500, 61, 23).contains(sf::Mouse::getPosition(window))) { exit.setColor(sf::Color::Blue); menuNum = 3; }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (menuNum == 3)  { window.close();}
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
                        if (board_logic.isMoveFigure(W_PAWN, curr_cage.x, curr_cage.y)) {
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
        window.draw(board_texture.get_sprite());

        for (size_t i = 0; i < 32; i++) {
            window.draw(f[i]);
        }
        window.display();
    }

    return 0;
}

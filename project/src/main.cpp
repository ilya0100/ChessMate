#include "chess.cpp"

size_t size = 52;

sf::Sprite f[32];

int board[8][8] =
    {{-5, -4, -3, -2, -1, -3, -4, -5},
     {-6, -6, -6, -6, -6, -6, -6, -6},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {0,  0,  0,  0,  0,  0,  0,  0},
      {6,  6,  6,  6,  6,  6,  6,  6},
      {5,  4,  3,  2,  1,  3,  4,  5}};

void loadPosition() {
    int k = 0;
    int n = 0;
    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            n = board[i][j];
            if (n) {
                int x = abs(n) - 1;
                int y = n > 0 ? 1 : 0;
                f[k].setTextureRect(sf::IntRect(size * x, size * y, size, size));
                f[k].setPosition(size * j, size * i);
                k++;
            }
        }
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(590, 590), "ChessMate!");

    Chess::Board board("images/boardT.jpg");
    Chess::FigureTexture sFigure("images/piecesT.png");

    for (size_t i = 0; i < 32; i++) {
        f[i].setTexture(sFigure.get_texture());
    }

    loadPosition();
    
    bool isMove = false;
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

            //drag and drop
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    for (size_t i = 0; i < 32; i++) {
                        if (f[i].getGlobalBounds().contains(pos.x, pos.y)) {
                            isMove = true;
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
                }
            }
            
        }

        if (isMove) { f[n].setPosition(pos.x - dx, pos.y - dy); }

        window.clear();
        window.draw(board.get_sprite());
        for (size_t i = 0; i < 32; i++) {
            window.draw(f[i]);
        }
        window.display();
    }

    return 0;
}

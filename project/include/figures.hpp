#include <SFML/Graphics.hpp>
#include <string>
#include "utils.h"

namespace Chess {
    class Figures {

        sf::Sprite figures[12];
        static size_t size = 52;

        public:

        void SetSprite(Figure_Name figure);
        void SetFigure(Figure_Name figure, Letter_Position l_p, Digit_Position d_p);

        friend
            Board::PutAllFiguresOnBoard();

    }

    class Rook : public Figures {
        Figure_Name Name;   // либо, либо {B_ROOK, W_ROOK}
        Figure_Side Side; // либо, либо {LEFT, RIGHT}
        Figure_Position Position;

        public:
            Rook(Figure_Name Rook = W_ROOK, Figure_Side S = LEFT);

    };

    class Knight : public Figures {
        Figure_Name Name;   //  либо, либо {B_KHIGHT, W_KNIGHT}
        Figure_Side Side;  //   либо, либо {LEFT, RIGHT}
        Figure_Position Position;

        public:
            Knight(Figure_Name Knight = W_KNIGHT, Figure_Side S = LEFT);


    };

    class Bishop : public Figures {
         Figure_Name Name;  //  либо, либо {B_BISHOP, W_BISHOP}
         Figure_Side Side;  //  либо, либо {LEFT, RIGHT}
         Figure_Position Position;

         public:
            Bishop(Figure_Name Bishop = W_BISHOP, Figure_Side S = LEFT);


    };

    class Queen : public Figures {
        Figure_Name Name;  // либо, либо {B_QUEEN, W_QUEEN}
        Figure_Position Position;

        public:
            Queen(Figure_Name Queen = W_QUEEN);

    };

    class King : public Figures {
        Figure_Name Name;  // либо, либо {B_KING, W_KING}
        Figure_Position Position;

        public:
            King(Figure_Name King = W_KING);

    };

    class Pawn : public Figures {
        Figure_Name Name;  // либо, либо {B_PAWN, W_PAWN}
        Pawn_Number P_Number;
        Figure_Position Position;

        public:
            Pawn(Figure_Name Pawn = W_PAWN, Pawn_Number P_Number = FIRST);

    };


namespace Chess {
    typedef struct Figure_Position{
        size_t pos_x;
        size_t pos_y;
    } Figure_Position

    typedef enum {
        B_ROOK,
        B_KNIGHT,
        B_BISHOP,
        B_QUEEN,
        B_KING,
        B_PAWN,
        W_ROOK,
        W_KNIGHT,
        W_BISHOP,
        W_QUEEN,
        W_KING,
        W_PAWN,
        VOID
    } Figure_Name;

    typedef enum {
        A,
        B,
        C,
        D,
        E,
        F,
        G,
        H
    } Letter_Position;

    typedef enum {
        EIGHT,
        SEVEN,
        SIX,
        FIVE,
        FOUR,
        THREE,
        TWO,
        ONE
    } Digit_Position;

    typedef enum {
        LEFT,
        RIGHT
    } Figure_Side;

    typedef enum {
        FIRST,
        SECOND,
        THIRD,
        FOURTH,
        FIFTH,
        SIXTH,
        SEVENTH,
        EIGHTH
    } Pawn_Number;

};
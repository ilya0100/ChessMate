#include <SFML/Graphics.hpp>
#include <string>

namespace Chess {

    class FigureTexture {
        sf::Texture texture;

    public:

        FigureTexture() = default;
        FigureTexture(std::string texture_file);
        
        sf::Texture get_texture();

    };

    class ChessFigure {
        size_t x;
        size_t y;

    public:
        ChessFigure(size_t new_x = 0, size_t new_y = 0);
        
        size_t get_x();
        size_t get_y();
    };

    class Pawn: public ChessFigure, public FigureTexture {
        std::vector<size_t> possible_positions_x;
        std::vector<size_t> possible_positions_y;
        sf::Sprite sprite;

    public:
        Pawn(FigureTexture texture);

        void set_poositions(ChessFigure figure);
    };
    
}  // namesapce Chess
#pragma once

#include "gameplay.hpp"

// figures
// #define SPRITE_SIZE 264



// static float size = SPRITE_SIZE * SCALE_FACTOR;

namespace Chess {

    void startMenu(Window & window);

    void selectMode(Window& window);
    void selectH(Window& window);

    void Test(Window & window);
    void startMenuN(Window & window);

    void startGame(Window& window, GameMode mode);

}  // namespace Chess

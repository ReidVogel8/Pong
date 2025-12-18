
#ifndef GAME_H
#define GAME_H
#include <Ball.h>
#include <Paddle.h>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Scoreboard.h"

class Game {
    public:
        Game();
        void startGame();
        void endGame();
        void resetGame();
    private:
        //score for both of the players
        static constexpr int WINDOW_WIDTH = 800.f;
        static constexpr int WINDOW_HEIGHT = 600.f;

        Paddle paddleLeft;
        Paddle paddleRight;
        Ball ball;
        Scoreboard scoreboard;
        sf::RenderWindow window;


        int scoreLeft = 0;
        int scoreRight = 0;
};

#endif //GAME_H

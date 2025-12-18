#include "Game.h"

#include <iostream>

#include "Ball.h"
#include "Paddle.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;


//constructor definition. Probably need to fix this pointer issue
Game::Game():
    paddleLeft(30.f, WINDOW_HEIGHT / 2.f - 50.f),
    paddleRight(WINDOW_WIDTH - 50.f, WINDOW_HEIGHT / 2.f - 50.f),
    ball(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f),
    scoreboard(WINDOW_WIDTH, WINDOW_HEIGHT/ 6.f, WINDOW_HEIGHT - WINDOW_HEIGHT / 6.f),
    window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pong"){
}

//most of the actual game code is going to live here in startGame
void Game::startGame() {

    while (window.isOpen()) {
        //set background color to black
        window.clear(Color::Black);

        //draw paddles and ball for each iteration (frames) and update score
        paddleLeft.draw(window);
        paddleRight.draw(window);
        ball.draw(window);
        scoreboard.draw(window);
        ball.move(window, paddleLeft, paddleRight, scoreboard);


        //Game movement
        //check bounds of right and move right paddle up or down if allowed
        if (!(paddleRight.getBounds().top <= 0)) {
            if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
                paddleRight.moveUp();
            }
        }
        if (!(paddleRight.getBounds().top + paddleRight.getBounds().height >= scoreboard.getBounds().top)) {
            if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
                paddleRight.moveDown();
            }
        }
        //same thing as above but moves the left paddle
        if (!(paddleLeft.getBounds().top <= 0)) {
            if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
                paddleLeft.moveUp();
            }
        }
        if (!(paddleLeft.getBounds().top + paddleRight.getBounds().height >= scoreboard.getBounds().top)) {
            if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
                paddleLeft.moveDown();
            }
        }

        //check if E key is pressed and will close the window
        if (Keyboard::isKeyPressed(Keyboard::Key::E)) {
            //endGame();
            window.close();
        }
        //show frames
        window.display();
    }
}


void Game::endGame() {

}


void Game::resetGame() {
    scoreLeft = 0;
    scoreRight = 0;
}
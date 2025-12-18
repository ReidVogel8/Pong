
#ifndef BALL_H
#define BALL_H
#include <Paddle.h>
#include <SFML/Graphics.hpp>

#include "scoreboard.h"

class Ball {
    public:
        //create ball and functionality for ball movement
        Ball(float x, float y);
        void draw(sf::RenderWindow& window) const;
        void move(sf::RenderWindow &window, const Paddle &left, const Paddle &right, Scoreboard &scoreboard);
        sf::FloatRect getBounds() const;

    private:
        sf::CircleShape shape{};
        sf::Vector2f velocity{};
        float xStart;
        float yStart;
        float speed;
};

#endif //BALL_H

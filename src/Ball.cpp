#include "Ball.h"
#include <cmath>
#include <Paddle.h>
#include <scoreboard.h>
#include <SFML/Graphics.hpp>

//constructor definition
Ball::Ball(float x, float y) {
    shape.setPosition(sf::Vector2f(x, y));
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::White);
    velocity = sf::Vector2f(1.f, 0.f);
    xStart = x;
    yStart = y;
    speed = 0.02f;
}


void Ball::draw(sf::RenderWindow &window) const{
    window.draw(shape);
}

//----------------Notes for collision-----------------------------
// Currently the ball will always start with the same speed going to the right. ->
// If someone scores the ball will go in the direction of the person who just got scored on ->
// Will have the ball slightly increase speed everytime a player hits it will a paddle ->
// there is no drawing to the window in the move function all that is done in Game.cpp ->
// Angle off paddle is determined how close to center. Farther away from center the more angle ->
// in the y direction with max of 60 degrees. This prevents own goals.
//----------------------------------------------------------------

void Ball::move(sf::RenderWindow& window, const Paddle& left, const Paddle& right, Scoreboard& scoreboard) {
    //if ball hits left paddle
    if (shape.getGlobalBounds().intersects(left.getBounds())) {
        //new plan, do the same thing by flipping axis but give certain values for y if below certain points?
        float paddleCenter = left.getBounds().top + (left.getBounds().height/2.f);
        float ballCenter = shape.getPosition().y +shape.getRadius();

        // goes from -1 to 1 where 0 is the center of the paddle
        float intersection = (ballCenter - paddleCenter) / (left.getBounds().height / 2.f);

        //make sure that never is outside -1 to 1
        if (intersection > 1.f) intersection = 1.f;
        if (intersection < -1.f) intersection = -1.f;

        // 60 degree angle max
        float angle = intersection * (3.14159f / 3.f);
        //get the new vector direction based of the angle
        velocity = sf::Vector2f(std::cos(angle), std::sin(angle));
        //slightly increase speed over time
        speed *= 1.5f;
    }
    // if ball hits right paddle
    if (shape.getGlobalBounds().intersects(right.getBounds())) {
        //new plan, do the same thing by flipping axis but give certain values for y if below certain points?
        float paddleCenter = right.getBounds().top + (right.getBounds().height/2.f);
        float ballCenter = shape.getPosition().y +shape.getRadius();

        // goes from -1 to 1 where 0 is the center of the paddle
        float intersection = (ballCenter - paddleCenter) / (right.getBounds().height / 2.f);

        //make sure that never is outside -1 to 1
        if (intersection > 1.f) intersection = 1.f;
        if (intersection < -1.f) intersection = -1.f;

        // 60 degree angle max
        float angle = intersection * (3.14159f / 3.f);

        velocity = sf::Vector2f(-std::cos(angle), std::sin(angle));

        speed *= 1.05f;
    }



    //if ball hits wall using 0 for top and 500 since height 600 and scoreboard 100. Would need to be changed ->
    //if the window size if changed. 100 less than window size.
    if (shape.getGlobalBounds().top <= 0 ||
        shape.getGlobalBounds().top + shape.getGlobalBounds().height >= window.getSize().y - 100) {
        velocity = sf::Vector2f((velocity.x), -1*(velocity.y));
    }

    //update position with new velocity and speed so when draw in game.cpp we get new position
    shape.setPosition(shape.getPosition().x + (velocity.x * speed),shape.getPosition().y + (velocity.y * speed));

    //GOALLLLLL!!!!! right score, Reset everything and put ball back to center
    if (shape.getPosition().x <= 0) {
        shape.setPosition(xStart, yStart);
        velocity = sf::Vector2f(-1*(1.f), 0.f);
        speed = 0.02f;
        scoreboard.updateRight();
    }
    //GOALLLLLL!!! left scores, Reset everything and put ball back to center.
    if (shape.getPosition().x >= window.getSize().x) {
        shape.setPosition(xStart, yStart);
        velocity = sf::Vector2f(1.f, 0.f);
        speed = 0.02f;
        scoreboard.updateLeft();
    }

}

sf::FloatRect Ball::getBounds() const {
    return shape.getGlobalBounds();
}
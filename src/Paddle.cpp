#include "Paddle.h"
#include <SFML/Graphics.hpp>

//constructor definition
Paddle::Paddle(float x, float y) {
    //setPosition uses a vector of x and y to show position values.
    shape.setPosition(sf::Vector2f(x, y));
    shape.setSize({20.f, 100.f});
    shape.setFillColor(sf::Color::White);
    speed = 0.03f;

}

void Paddle::moveUp() {
    shape.setPosition(shape.getPosition().x, shape.getPosition().y - speed); //move the paddle up
}

void Paddle::moveDown() {
    shape.setPosition(shape.getPosition().x, shape.getPosition().y + speed); //move the paddle down
}

void Paddle::draw(sf::RenderWindow &window) const {
    window.draw(shape);  //draw 2d paddle
}

void Paddle::update(float t) {
    //do nothing at this time
}

sf::FloatRect Paddle::getBounds() const{
    return shape.getGlobalBounds(); //used for collision detection with the ball
}
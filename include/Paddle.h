
#ifndef PADDLE_H
#define PADDLE_H
#include <SFML/Graphics.hpp>

class Paddle {

public:
    //constructor
    Paddle(float x, float y);
    //create paddle and functionality for moving it
    void moveUp();
    void moveDown();
    void update(float time);
    void draw(sf::RenderWindow &window) const;
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape{};
    float speed{};
};


#endif //PADDLE_H

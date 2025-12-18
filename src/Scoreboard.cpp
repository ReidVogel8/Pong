#include "Scoreboard.h"
#include "SFML/Graphics.hpp"

Scoreboard::Scoreboard(float x ,float y, float z) {
    //z is used for getting the scoreboard at the bottom of the screen. bottom 100 pixels used for scoreboard
    box.setSize(sf::Vector2f(x,y));
    box.setPosition(sf::Vector2f(0,z));
    box.setFillColor(sf::Color::White);
    if (!font.loadFromFile("../assets/fonts/LEMONMILK-Regular.otf")) {
        throw std::runtime_error("Failed to load font");
    }

    //setting scoreboard values fonts and position
    leftText.setString("0");
    rightText.setString("0");
    leftText.setFont(font);
    rightText.setFont(font);
    leftText.setCharacterSize(60);
    rightText.setCharacterSize(60);
    leftText.setFillColor(sf::Color::Black);
    rightText.setFillColor(sf::Color::Black);
    //y divided by 6 gotten from window frame size being 600. divide by size of scoreboard height and window height. 600/100 = 6
    leftText.setPosition(sf::Vector2f(box.getPosition().x + box.getSize().x/4, box.getPosition().y+box.getSize().y/6));
    rightText.setPosition(sf::Vector2f(box.getPosition().x + box.getSize().x/1.5, box.getPosition().y+box.getSize().y/6));
}

int Scoreboard::getLeftScore() const {
    return leftScore;
}

int Scoreboard::getRightScore() const {
    return rightScore;
}

void Scoreboard::updateRight() {
    rightScore++;
    rightText.setString(std::to_string(rightScore));
}

void Scoreboard::updateLeft() {
    leftScore++;
    leftText.setString(std::to_string(leftScore));
}

void Scoreboard::draw(sf::RenderWindow &window) const{
    window.draw(box);
    window.draw(leftText);
    window.draw(rightText);
}


sf::FloatRect Scoreboard::getBounds() const{
    return box.getGlobalBounds(); //used for collision detection with the ball
}


#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <Scoreboard.h>
#include "SFML/Graphics.hpp"

class Scoreboard {

    public:
        Scoreboard(float x, float y, float z);
        int getLeftScore() const;
        int getRightScore() const;
        void updateLeft();
        void updateRight();
        void draw(sf::RenderWindow& window) const;
        sf::FloatRect getBounds() const;


    private:
        sf::RectangleShape box{};

        sf::Font font{};
        sf::Text leftText{};
        sf::Text rightText{};
        int leftScore = 0;
        int rightScore = 0;
};
#endif //SCOREBOARD_H

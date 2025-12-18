
#include "../include/Game.h"

//------------------------notes------------------------------
// This is an endless game that will continue to update the score until 'E' is pressed to exit the game. ->
// the ball will continue to get faster the more it touches either paddle to help increase scoring. ->
// github will have more information. Future updates could add an end screen if a player gets to a certain score ->
// inside the endGame() function. Cmake file is running on windows.
//-----------------------------------------------------------

int main() {
    //start a new game of pong on the stack
    Game game;
    game.startGame();
    return 0;
}

#include "title.hpp"
#include <iostream>

std::string playerName;

int titleScreen() {

    //This is the title screen. It will be the first thing the player sees when they start the game.
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "TRIVIA GAUNTLET\n";
    std::cout << "Press Enter to continue...\n";
    std::cout << "-------------------------------------------------------------\n";
    getchar();

    //Once the player presses enter, they will be prompted to enter a name.
    //If no name is entered, the default name "Player" will be used.
    std::cout << "Enter a name: \n";

    std::getline(std::cin, playerName);
    if (playerName.empty())
    playerName = "Player";

    return 0;

}
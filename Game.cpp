#include <iostream>
#include <string>
#include <random>
#include "hitpoints.h"
#include "interactions.h"
#include "room.h"
#include "item.h"

int action = 0;
void initialize_game() {
    int start_button;
    std::cout << "Billy The Knight" << std::endl;

    //while the start button is not 1 it will keep asking the user to press 1 to start the game.
    while (start_button !=1)
    {
        std::cout << "Press 1 to start: ";
        std::cin >> start_button;

        //The game starts if the user enters 1, otherwise it will keep asking the user to press 1 to start the game.
        if (start_button == 1) {
        std::cout << "Starting the game..." << std::endl;
        //This return brings you back to main() and runs the next function (LevelOne).
        return;
    
        } else {
        std::cout << "Not starting. You entered: " << start_button << std::endl;
        //calling initialize game again restarts the query to start the game.
        initialize_game();
        }
    
    }

}


void YouDied() {
        std::cout << "GAME OVER. You died. Skill Issue. Git Gud." << std::endl;
        std::cout << "Press 1 to restart, or any other key to exit: ";
        int restart_button;
        std::cin >> restart_button;
        if (restart_button == 1) {
            std::cout << "Restarting the game..." << std::endl;
            initialize_game();
        } else {
            std::cout << "Exiting the game. You entered: " << restart_button << std::endl;
            exit(0);
        }
}


int main() {
    //Start button for the game function
    initialize_game();
    //This is where the first level of the game will be called.
    weapon_select();
    get_random_foe();
    room_one();
    //This is where the battle system will be


}


//test comment
//second test conmment
//another comment

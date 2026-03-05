#include <iostream>
#include <string>
#include <random>
#include <limits>

#include "character.hpp"
#include "battle.hpp"
#include "trivia.hpp"
#include "title.hpp"

int main(){

    titleScreen();
    
    int classChoice = charSelect();
    
//Creates player based on class selection
    Fighter player{};
    Fighter enemies[3];
    
    if (classChoice == 1) {
        player = warrior(playerName);
        enemies[0] = goblin();
        enemies[1] = ogre();
        enemies[2] = dragon();
    }
    else if (classChoice == 2) {
        player = mage(playerName);
        enemies[0] = zombie();
        enemies[1] = minotaur();
        enemies[2] = dragon();
    }
    else {
        player = hunter(playerName);
        enemies[0] = wolf();
        enemies[1] = demonSpawn();
        enemies[2] = dragon();
    }
    
    std::cout << "\nYou chose: " << player.className << ".\n";
    std::cout << "Prepare yourself...\n";
    
//Creates RNG and runs gauntlet
    RNG rng;
    battleLoop(player, enemies, rng);

}
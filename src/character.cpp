#include "character.hpp"
#include "title.hpp"
#include <iostream>
#include <string>
#include <limits>

//Types are declared in character.hpp

Fighter warrior(const std::string& playerName) {

    Fighter f{};
    f.name = playerName;
    f.className = "Warrior";
    f.maxHP = 120; f.hp = 120;
    f.atk = 14; f.def = 10; f.spd = 7;
    f.defBuff = 0;

    //the numbers at the end are attack power,
    //accuracy and critical hit chance values, for example
    //18,90,15 would be attack power 18 with 90 percent accuracy and 15 percent crit chance.
    f.moves[0] = {"Slash", MoveKind::Attack, 18, 90, 15};
    f.moves[1] = {"Shield Bash", MoveKind::Attack, 14, 95, 10};
    f.moves[2] = {"Fortify", MoveKind::Defend, 6, 95, 0};
    f.moves[3] = {"Second Wind", MoveKind::Heal, 22, 90, 0};

    return f;

}

Fighter mage(const std::string& playerName) {

    Fighter f{};
    f.name = playerName;
    f.className = "Mage";
    f.maxHP = 90; f.hp = 90;
    f.atk = 18; f.def = 6; f.spd = 9;
    f.defBuff = 0;

    f.moves[0] = {"Arc Bolt", MoveKind::Attack, 22, 85, 20};
    f.moves[1] = {"Fire Lance", MoveKind::Attack, 26, 80, 25};
    f.moves[2] = {"Barrier", MoveKind::Defend, 5, 90, 0};
    f.moves[3] = {"Mend", MoveKind::Heal, 24, 90, 0};

    return f;

}

Fighter hunter(const std::string& playerName) {

    Fighter f{};
    f.name = playerName;
    f.className = "Hunter";
    f.maxHP = 100; f.hp = 100;
    f.atk = 15; f.def = 7; f.spd = 12;
    f.defBuff = 0;

    //Unique moves created for the hunter with 
    f.moves[0] = {"Quick Shot", MoveKind::Attack, 16, 95, 15};
    f.moves[1] = {"Power Arrow", MoveKind::Attack, 24, 80, 25};
    f.moves[2] = {"Evasive Step", MoveKind::Defend, 4, 95, 0};
    f.moves[3] = {"Field Dress", MoveKind::Heal, 18, 95, 0};

    return f;

}

Fighter goblin() {

//This will be the first enemy for the player if they choose the WARRIOR class.
    Fighter e{};
    e.name = "Goblin";
    e.className = "Enemy";
    e.maxHP = 70; e.hp = 70;
    e.atk = 10; e.def = 6; e.spd = 8;
    e.defBuff = 0;
    e.lastMove = -1;

//The enemies will have a four command option like the user.
    e.moves[0] = {"Rusty Stab", MoveKind::Attack, 14, 85, 10};
    e.moves[1] = {"Dirty Kick", MoveKind::Attack, 12, 90, 8};
    e.moves[2] = {"Scamper", MoveKind::Defend, 3, 95, 0};
    e.moves[3] = {"Gnawed Herb", MoveKind::Heal, 12, 85, 0};

    return e;

}

Fighter zombie() {
    
//This will be the first enemy for the player if they choose the MAGE class.
    Fighter e{};
    e.name = "Zombie";
    e.className = "Enemy";
    e.maxHP = 70; e.hp = 70;
    e.atk = 12; e.def = 8; e.spd = 5;
    e.defBuff = 0;
    e.lastMove = -1;

    e.moves[0] = {"Undead Lunge", MoveKind::Attack, 15, 75, 10};
    e.moves[1] = {"Infected Bite", MoveKind::Attack, 17, 60, 40};
    e.moves[2] = {"Mindless Guard", MoveKind::Defend, 1, 90, 0};
    e.moves[3] = {"Amateur Magic", MoveKind::Heal, 20, 85, 0};

    return e;

}

Fighter wolf() {

//This will be the first enemy for the player if they choose the HUNTER class.
    Fighter e{};
    e.name = "Wolf";
    e.className = "Enemy";
    e.maxHP = 70; e.hp = 70;
    e.atk = 10; e.def = 6; e.spd = 8;
    e.defBuff = 0;
    e.lastMove = -1;

    e.moves[0] = {"Chomp", MoveKind::Attack, 16, 70, 10};
    e.moves[1] = {"Claw Swipe", MoveKind::Attack, 22, 65, 16};
    e.moves[2] = {"Cower", MoveKind::Defend, 3, 90, 0};
    e.moves[3] = {"Lick Wounds", MoveKind::Heal, 14, 85, 0};

    return e;

}

Fighter ogre() {

//This will be the second enemy for the player if they choose the WARRIOR class.
    Fighter e{};
    e.name = "Ogre";
    e.className = "Enemy";
    e.maxHP = 90; e.hp = 90;
    e.atk = 15; e.def = 9; e.spd = 8;
    e.defBuff = 0;
    e.lastMove = -1;

    e.moves[0] = {"Clobber", MoveKind::Attack, 20, 85, 10};
    e.moves[1] = {"Tackle", MoveKind::Attack, 25, 80, 8};
    e.moves[2] = {"Brace", MoveKind::Defend, 6, 95, 0};
    e.moves[3] = {"Gorge", MoveKind::Heal, 15, 85, 0};

    return e;

}

Fighter minotaur() {
    
//This will be the seecond enemy for the player if they choose the MAGE class.
    Fighter e{};
    e.name = "Minotaur";
    e.className = "Enemy";
    e.maxHP = 95; e.hp = 95;
    e.atk = 15; e.def = 9; e.spd = 10;
    e.defBuff = 0;
    e.lastMove = -1;

    e.moves[0] = {"Charge", MoveKind::Attack, 30, 70, 30};
    e.moves[1] = {"Axe Strike", MoveKind::Attack, 40, 50, 40};
    e.moves[2] = {"Fortify", MoveKind::Defend, 4, 90, 0};
    e.moves[3] = {"Regenerate", MoveKind::Heal, 20, 85, 0};

    return e;

}

Fighter demonSpawn() {

//This will be the first enemy for the player if they choose the HUNTER class.
    Fighter e{};
    e.name = "Demon Spawn";
    e.className = "Enemy";
    e.maxHP = 85; e.hp = 85;
    e.atk = 17; e.def = 7; e.spd = 14;
    e.defBuff = 0;
    e.lastMove = -1;

    e.moves[0] = {"Fireball", MoveKind::Attack, 20, 85, 25};
    e.moves[1] = {"Stab", MoveKind::Attack, 25, 80, 20};
    e.moves[2] = {"Wing Shield", MoveKind::Defend, 8, 90, 0};
    e.moves[3] = {"Dark Magic", MoveKind::Heal, 10, 85, 0};

    return e;

}

//If you want to add another wave of enemies, probably best to put them here.

Fighter dragon() {

//This will be the final boss for all classes.
    Fighter e{};
    e.name = "Dragon";
    e.className = "Enemy";
    e.maxHP = 150; e.hp = 150;
    e.atk = 25; e.def = 15; e.spd = 12;
    e.defBuff = 0;
    e.lastMove = -1;

    e.moves[0] = {"Flame Breath", MoveKind::Attack, 50, 80, 20};
    e.moves[1] = {"Tail Swipe", MoveKind::Attack, 45, 85, 15};
    e.moves[2] = {"Scale Harden", MoveKind::Defend, 5, 90, 0};
    e.moves[3] = {"Roar", MoveKind::Heal, 15, 85, 0};

    return e;

}

int charSelect() {

    //Prompts user to select a character

    std::cout << "--------------------- Select your class ---------------------\n";
    std::cout << "[1] WARRIOR: High HP/DEF, steady damage\n";
    std::cout << "[2] MAGE: High damage/crit, low DEF\n";
    std::cout << "[3] HUNTER: High speed, reliable attacks\n";
    std::cout << "-------------------------------------------------------------\n";

    //The player types in a number from 1-3

    int character;
    std::cin >> character;

    //If the player types 1, launch WARRIOR function, and so on
    //If the player types something else, prompt them to type a number from 1-3 until they do

    while(character < 1 || character > 3) {
        std::cout << "Please type a number from 1 to 3\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> character;
    }

    return character;

}
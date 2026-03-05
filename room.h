#include <iostream>
#include <random>
#include "interactions.h"

int get_random_foe() {
    static std::random_device rd;  
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 3);

    return dist(gen);
}

void room_one() {
    int Wait =0;
    int foe = get_random_foe();
    std::string foeName = "";
    if (foe == 1) {
        foeName = "Skeleton";
    } else if (foe == 2) {
        foeName = "Troll";
    } else if (foe == 3) {
        foeName = "Swarm of Cicadas";
    }
    std::cout << "A Dangerous foe appears in the first room of the Admissions Building" << std::endl;
    std::cout << "The foe is a:" << foeName << std::endl;
    std::cout << "What will you do? (1: Fight/n 2: Check Inventory/n 3: Check HP): ";
    std::cin >> action;
    if (action ==1) {
        damage_interaction();
    }

    std::cin >> Wait;

}

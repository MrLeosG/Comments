#include <iostream>
#include "hitpoints.h"

class Item {
    private:
        std::string name;

    public:
        //construct item
        Item(std::string item_name) {
            name = item_name;
        }

        //grab the name
        std::string get_name() {
            return name;
        }
};

void weapon_select() {

    int item_collected = 0;
    std::string item_name;
    Item leaf_blade("The Leaf Blade");
    Item infernal_wand("The Infernal Wand");
    Item aquatic_shield("The Aquatic Shield");

    std::cout << "Pick a Weapon!" << std::endl;
    std::cout << "Which item do you want to collect? \n(1: The Leaf Blade\n 2: The Infernal Wand\n 3: The Aquatic Shield): ";
    std::cin >> item_collected;
    
    if (item_collected == 1) {
        item_name = "The Leaf Blade";
    } else if (item_collected == 2) {
        item_name = "The Infernal Wand";
    } else if (item_collected == 3) {
        item_name = "The Aquatic Shield";
    } else {
        std::cout << "Invalid item selection. You collected nothing. Goofball" << std::endl;
        
    while (true) {
        std::cin >> item_collected;

        if (item_collected >= 1 && item_collected <= 3)
            break;

        std::cout << "Invalid selection. Try again: ";
    }
    }
    std::cout << "You collected: " << item_name << std::endl;
    return;
}

#include "trivia.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <limits>

int randTrivia1() {

    //This function will generate a random trivia question for the player to answer. If the player answers correctly, they will successfully dodge the attack. If they answer incorrectly, they will take damage.

    std::srand(std::time(0));

    std::cout << "========================== QUESTION ==========================\n";

    char arrayString0[]{ "What is a word, phrase, number, or other sequence of characters that reads the same backward as forward?" };
    char arrayString1[]{ "What is the world's largest retailer as of 2026?" };
    char arrayString2[]{ "What is the most widely watched sport in the US?" };
    char arrayString3[]{ "What is the capital of France?" };
    char arrayString4[]{ "What is the largest planet in our solar system?" };
    char arrayString5[]{ "What is the chemical symbol for gold?" };
    char arrayString6[]{ "What is 110/10?" };
    char arrayString7[]{ "What is the longest river in the world?" };
    char arrayString8[]{ "What is the name of the tallest mountain in the world? (do not include the word 'mountain')" };
    char arrayString9[]{ "What is the smallest country in the world?" };

    bool end {false};
    std::string answer;

        while(!end) {

            size_t rand_num = static_cast<size_t>((std::rand() % 10));

            switch (rand_num) { // [0~10]
            case 0:
                std::cout << arrayString0 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "palindrome") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is palindrome.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 1:
                std::cout << arrayString1 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "walmart") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is walmart.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 2:
                std::cout << arrayString2 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "football") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is football.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 3:
                std::cout << arrayString3 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "paris") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is paris.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 4:
                std::cout << arrayString4 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "jupiter") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is jupiter.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 5:
                std::cout << arrayString5 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "au") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is au.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 6:
                std::cout << arrayString6 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "11") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is 11.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 7:
                std::cout << arrayString7 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "nile") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is nile.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 8:
                std::cout << arrayString8 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "everest") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is everest.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 9:
                std::cout << arrayString9 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "vatican") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is vatican.\n";
                        return 0;
                    }
                    end = true;
                    break;
            default:
                std::cout << "Error: Question not found.\n";
                end = true;
                break;
            }

    }

    return 0;

}

int randTrivia2() {

    //This function will generate a random trivia question for the player to answer. If the player answers correctly, they will successfully dodge the attack. If they answer incorrectly, they will take damage.

    std::srand(std::time(0));

    std::cout << "========================== QUESTION ==========================\n";

    char arrayString0[]{ "Which mineral is commonly known as fools' gold?" };
    char arrayString1[]{ "Which animation technique involves tracing over live-action footage to create more realistic character movements?" };
    char arrayString2[]{ "Which Floridian type of aquatic mammal is typically pregnant for up to a year?" };
    char arrayString3[]{ "What is the smallest prime number?" };
    char arrayString4[]{ "What do you call the ancient symbol that features a snake eating its own tail?" };
    char arrayString5[]{ "What is the hardest natural substance on Earth?" };
    char arrayString6[]{ "In what year was the first iPhone released?" };
    char arrayString7[]{ "Who is the Roman goddess of love?" };
    char arrayString8[]{ "What is the second largest country by land area?" };
    char arrayString9[]{ "What is the largest organ of the human body?" };

    bool end {false};
    std::string answer;

        while(!end) {

            size_t rand_num = static_cast<size_t>((std::rand() % 10));

            switch (rand_num) { // [0~10]
            case 0:
                std::cout << arrayString0 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "pyrite") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is pyrite.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 1:
                std::cout << arrayString1 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "rotoscoping") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is rotoscoping.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 2:
                std::cout << arrayString2 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "manatee") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is manatee.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 3:
                std::cout << arrayString3 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "2") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is 2.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 4:
                std::cout << arrayString4 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "ouroboros") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is ouroboros.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 5:
                std::cout << arrayString5 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "diamond") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is diamond.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 6:
                std::cout << arrayString6 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "2007") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is 2007.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 7:
                std::cout << arrayString7 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "venus") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is venus.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 8:
                std::cout << arrayString8 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "canada") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is canada.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 9:
                std::cout << arrayString9 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "skin") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is skin.\n";
                        return 0;
                    }
                    end = true;
                    break;
            default:
                std::cout << "Error: Question not found.\n";
                end = true;
                break;
            }

    }

    return 0;

}

int randTrivia3() {

    //This function will generate a random trivia question for the player to answer. If the player answers correctly, they will successfully dodge the attack. If they answer incorrectly, they will take damage.

    std::srand(std::time(0));

    std::cout << "========================== QUESTION ==========================\n";

    char arrayString0[]{ "Which nation's flag the only one in the world that does not have four sides?" };
    char arrayString1[]{ "How many elements are there on the periodic table?" };
    char arrayString2[]{ "Who was the world's highest-paid athlete in 2023? (Please enter the last name only)" };
    char arrayString3[]{ "What animal has the largest brain relative to its body size?" };
    char arrayString4[]{ "Which 1977 album is the best-selling of all time worldwide?" };
    char arrayString5[]{ "What is the term for animals that maintain a constant body temperature?" };
    char arrayString6[]{ "Which search engine was orginally called 'Backrub'?" };
    char arrayString7[]{ "What is the capital of Austrailia?" };
    char arrayString8[]{ "What is the currency of Iran?" };
    char arrayString9[]{ "According to Greek mythology, who was the first woman on earth?" };

    bool end {false};
    std::string answer;

        while(!end) {

            size_t rand_num = static_cast<size_t>((std::rand() % 10));

            switch (rand_num) { // [0~10]
            case 0:
                std::cout << arrayString0 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "nepal") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is nepal.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 1:
                std::cout << arrayString1 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "118") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is 118.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 2:
                std::cout << arrayString2 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "ronaldo") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is ronaldo.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 3:
                std::cout << arrayString3 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "dolphin") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is dolphin.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 4:
                std::cout << arrayString4 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "thriller") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is thriller.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 5:
                std::cout << arrayString5 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "endotherms") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is endotherms.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 6:
                std::cout << arrayString6 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "google") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is google.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 7:
                std::cout << arrayString7 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "canberra") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is canberra.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 8:
                std::cout << arrayString8 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "rial") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is rial.\n";
                        return 0;
                    }
                    end = true;
                    break;
            case 9:
                std::cout << arrayString9 << std::endl;
                std::cin >> answer;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    if (answer == "pandora") {
                        std::cout << "Correct! Attack successfully dodged!\n";
                        return 1;
                    }
                    else {
                        std::cout << "Wrong! The correct answer is pandora.\n";
                        return 0;
                    }
                    end = true;
                    break;
            default:
                std::cout << "Error: Question not found.\n";
                end = true;
                break;
            }

    }

    return 0;

}
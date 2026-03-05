#include "battle.hpp"
#include "character.hpp"
#include "trivia.hpp"
#include <random>
#include <iostream>

// RNG struct is now defined in character.hpp

void clearInputLine() {

//Clears the input buffer after reading an int, to avoid leftover input causing issues.
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

int computeDamage(const Fighter& attacker, const Fighter& defender, const Move& move, bool crit) {

//base = the move's power + the attacker's attack stat - the defender's defense stat (including buffs). Minimum base is 1.
//crit multiplies by 1.5 (rounded down)
    int effectiveDef = defender.def + defender.defBuff;

    int base = move.power + attacker.atk - effectiveDef;
    if (base < 1) base = 1;

    if (crit) {
        base = (base * 3) / 2; // 1.5x
        if (base < 1) base = 1;
    }

    return base;

}

static bool attemptDodge(int difficultyLevel) {

//Call a trivia question. If answered correctly, the attack is dodged (returns true). If incorrect, attack hits (returns false).
    if (difficultyLevel == 1) {
        return randTrivia1() == 1;
    } else if (difficultyLevel == 2) {
        return randTrivia2() == 1;
    } else if (difficultyLevel == 3) {
        return randTrivia3() == 1;
    }
    return false; // fallback

}

void applyMove(Fighter* attacker, Fighter* defender, Move* move, RNG& rng, int difficultyLevel = 0, bool isPlayerDefender = false) {

//Pointers used intentionally so HP and buffs update the real fighters.
    std::cout << attacker->name << " used " << move->name << "!\n";

//Accuracy check (yes, even heals/defends can miss)
    if (!rng.chance(move->accuracy)) {

        std::cout << "It missed!\n";
        return;

    }

    // If the move is an attack and the defender is the player, give them a dodge chance via trivia
    if (move->kind == MoveKind::Attack && isPlayerDefender && difficultyLevel > 0) {
        std::cout << defender->name << ", answer a trivia question to dodge the attack!\n";
        if (attemptDodge(difficultyLevel)) {
            return; // Attack was completely avoided
        }
        std::cout << "Failed to dodge! Taking damage...\n";
    }

    switch (move->kind) {
        case MoveKind::Attack: {

            bool crit = rng.chance(move->critChance);
            int dmg = computeDamage(*attacker, *defender, *move, crit);
            defender->hp -= dmg;
            if (defender->hp < 0) defender->hp = 0;

            if (crit) std::cout << "Critical hit!\n";
            std::cout << defender->name << " took " << dmg << " damage.\n";
            break;

        }
        case MoveKind::Heal: {

            int heal = move->power;
            int before = attacker->hp;
            attacker->hp += heal;
            if (attacker->hp > attacker->maxHP) attacker->hp = attacker->maxHP;
            std::cout << attacker->name << " healed " << (attacker->hp - before) << " HP.\n";
            break;

        }
        case MoveKind::Defend: {

            attacker->defBuff += move->power;
            std::cout << attacker->name << "'s defense rose by " << move->power << "!\n";
            break;

        }
    }
}

Move* chooseEnemyMove(Fighter* enemy, RNG& rng) {

//Picks a random move for the enemy, but tries to avoid picking the same move twice in a row.
    int pick = rng.rollInt(0, 3);
    if (enemy->lastMove >= 0 && enemy->lastMove <= 3) {
        int tries = 0;
        while (pick == enemy->lastMove && tries < 10) {
            pick = rng.rollInt(0, 3);
            ++tries;
        }
    }
    enemy->lastMove = pick;
    return &enemy->moves[pick];

}

void startOfTurnCleanup(Fighter* f) {

//Lets defense buff decay slowly so "defend stacking" isn't broken. Decays 1 point per turn.
    if (f->defBuff > 0) f->defBuff -= 1;

}

void printHPBar(const Fighter& f) {

//Simple bar of 20 blocks
    const int barWidth = 20;
    int filled = (f.maxHP > 0) ? (f.hp * barWidth) / f.maxHP : 0;
    if (filled < 0) filled = 0;
    if (filled > barWidth) filled = barWidth;

    std::cout << f.name << " (" << f.className << ")\n";
    std::cout << "HP: " << f.hp << "/" << f.maxHP << "  [";
    for (int i = 0; i < barWidth; i++) std::cout << (i < filled ? '#' : '-');
    std::cout << "]\n";
    std::cout << "ATK: " << f.atk << "  DEF: " << f.def << "  SPD: " << f.spd
         << "  (DEF Buff: +" << f.defBuff << ")\n";

}

void showMoves(const Fighter& player) {

//Displays the player's moves with their stats, and prompts the player to choose one.
    std::cout << "\nChoose a move:\n";
    for (int i = 0; i < 4; i++) {
        const Move& m = player.moves[i];
        std::cout << "  " << (i + 1) << ") " << m.name;

        if (m.kind == MoveKind::Attack) {
            std::cout << "  [Attack | Power " << m.power << " | Acc " << m.accuracy
                 << "% | Crit " << m.critChance << "%]";
        } else if (m.kind == MoveKind::Heal) {
            std::cout << "  [Heal   | +" << m.power << " HP | Acc " << m.accuracy << "%]";
        } else {
            std::cout << "  [Defend | +" << m.power << " DEF | Acc " << m.accuracy << "%]";
        }
        std::cout << "\n";
    }

}

int promptChoiceInt(const std::string& prompt, int minVal, int maxVal) {

//Prompts the user to enter an integer between minVal and maxVal, and validates the input.
    while (true) {
        std::cout << prompt;
        int x;
        if (std::cin >> x && x >= minVal && x <= maxVal) {
            clearInputLine();
            return x;
        }
        clearInputLine();
        std::cout << "Invalid input. Choose " << minVal << " to " << maxVal << ".\n";
    }

}

void battle(Fighter* player, Fighter* enemy, RNG& rng, int difficultyLevel) {

    std::cout << "\n==============================\n";
    std::cout << "ENCOUNTER: " << enemy->name << " appears!\n";
    std::cout << "==============================\n";

    // Reset temporary buffs at battle start
    player->defBuff = 0;
    enemy->defBuff = 0;
    player->lastMove = -1;
    enemy->lastMove = -1;

    while (player->hp > 0 && enemy->hp > 0) {
        std::cout << "\n--- STATUS ---\n";
        printHPBar(*player);
        std::cout << "\n";
        printHPBar(*enemy);

        //Speed decides order each round (tie -> player first)
        bool playerFirst = (player->spd >= enemy->spd);

        //Shows moves and prompts player to choose one, or picks a random move for the enemy, depending on who goes first.
        if (playerFirst) {
            startOfTurnCleanup(player);
            showMoves(*player);
            int choice = promptChoiceInt("Enter 1-4: ", 1, 4);
            Move* playerMove = &player->moves[choice - 1]; // pointer to chosen move
            applyMove(player, enemy, playerMove, rng, 0, false); // Player attacks, no dodge for enemy
            if (enemy->hp <= 0) break;

            startOfTurnCleanup(enemy);
            Move* enemyMove = chooseEnemyMove(enemy, rng);
            applyMove(enemy, player, enemyMove, rng, difficultyLevel, true); // Enemy attacks, player can dodge via trivia
        } else {
            startOfTurnCleanup(enemy);
            Move* enemyMove = chooseEnemyMove(enemy, rng);
            applyMove(enemy, player, enemyMove, rng, difficultyLevel, true); // Enemy attacks, player can dodge via trivia
            if (player->hp <= 0) break;

            startOfTurnCleanup(player);
            showMoves(*player);
            int choice = promptChoiceInt("Enter 1-4: ", 1, 4);
            Move* playerMove = &player->moves[choice - 1];
            applyMove(player, enemy, playerMove, rng, 0, false); // Player attacks, no dodge for enemy
        }
    }

    //Displays the outcome of the battle. If the player's HP is 0 or less, they were defeated. Otherwise, the enemy was defeated.
    if (player->hp <= 0) {
        std::cout << "\n" << player->name << " was defeated...\n";
    } else {
        std::cout << "\n" << enemy->name << " was defeated!\n";
        int difficultyLevel = difficultyLevel + 1;
    }

}

static void fullHeal(Fighter* f) {

//The player should regain full health after each successful fight.
    f->hp = f->maxHP;
    f->defBuff = 0;

}

static void applyReward(Fighter* player) {

//The player will have the choice to select a level upgrade.
    std::cout << "\nReward time. Choose ONE:\n";
    std::cout << "  1) +15 Max HP\n";
    std::cout << "  2) +3 ATK\n";
    std::cout << "  3) +3 DEF\n";
    std::cout << "  4) +2 SPD\n";

    int r = promptChoiceInt("Enter 1-4: ", 1, 4);
    switch (r) {
        case 1: player->maxHP += 15; player->hp = player->maxHP; break;
        case 2: player->atk += 3; break;
        case 3: player->def += 3; break;
        case 4: player->spd += 2; break;
    }
    std::cout << "Reward applied.\n";

}

int battleLoop(Fighter& player, Fighter enemies[3], RNG& rng) {

    // loop over predefined enemies; rng provided by caller
    for (int i = 0; i < 3; i++) {

        //enemies[0] is level 1, enemies[1] is level 2, enemies [3] is dragon
        //The loop should allow us to fight these bosses in a set order.


        // This is a pointer to the enemy
        //Fighter points to a fighter
        //enemies[i] fighter object at index i where i = 0,1,or 2
        Fighter* currentEnemy = &enemies[i];

        // Ensure enemy HP is reset (when retry activated)
        currentEnemy->hp = currentEnemy->maxHP;
        currentEnemy->defBuff = 0;
        currentEnemy->lastMove = -1;

        battle(&player, currentEnemy, rng, i + 1);
        if (player.hp <= 0) {
            std::cout << "\nRun ended at fight " << (i + 1) << " / 3.\n";
            std::cout << "GAME OVER.\n";
            return 0;
        }

        // Full heal and after victory loot
        std::cout << "\nYou are fully healed before the next fight.\n";
        fullHeal(&player);
        applyReward(&player);
    }

    std::cout << "\n==============================\n";
    std::cout << "VICTORY.\n";
    std::cout << player.name << " cleared the gauntlet.\n";
    std::cout << "==============================\n";

    return 1;

}
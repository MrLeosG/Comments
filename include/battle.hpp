#ifndef BATTLE_HPP
#define BATTLE_HPP
#include "character.hpp"

//FUNCTION DISPLAYS THE BATTLE BETWEEN THE PLAYER AND AN ENEMY, TAKING INTO ACCOUNT SPEED, BUFFS, AND OTHER FACTORS.
//USES THE RNG STRUCT FOR RANDOMNESS IN MOVES.
//THE PLAYER CAN ANSWER TRIVIA QUESTIONS TO DODGE ENEMY ATTACKS (DIFFICULTY 1-3).
void battle(Fighter* player, Fighter* enemy, RNG& rng, int difficultyLevel = 1);

// helper that runs through the three-enemy gauntlet. player and enemies must be defined by caller.
int battleLoop(Fighter& player, Fighter enemies[3], RNG& rng);

//FUNCTION TO PROMPT THE USER TO CHOOSE A MOVE, WITH VALIDATION.
int promptChoiceInt(const std::string& prompt, int minVal, int maxVal);

//DISPLAYS THE HP BAR AND STATS OF A FIGHTER IN A USER-FRIENDLY WAY.
void printHPBar(const Fighter& f);

//SHOWS THE PLAYER'S MOVES WITH THEIR STATS, AND PROMPTS THE PLAYER TO CHOOSE ONE.
void showMoves(const Fighter& player);

//FUNCTION TO CLEAR THE INPUT BUFFER AFTER READING AN INT, TO AVOID LEFTOVER INPUT CAUSING ISSUES.
void clearInputLine();

//FUNCTION TO DECAY THE DEFENSE BUFF AT THE START OF A FIGHTER'S TURN, TO PREVENT "DEFEND STACKING" FROM BEING BROKEN.
void startOfTurnCleanup(Fighter* f);

//FUNCTION TO PICK A RANDOM MOVE FOR THE ENEMY, BUT TRIES TO AVOID PICKING THE SAME MOVE TWICE IN A ROW.
Move* chooseEnemyMove(Fighter* enemy, RNG& rng);

//FUNCTION TO COMPUTE THE DAMAGE OF AN ATTACK MOVE, TAKING INTO ACCOUNT THE ATTACKER'S ATK,
//THE DEFENDER'S DEF (INCLUDING BUFFS), THE MOVE'S POWER, AND WHETHER IT'S A CRITICAL HIT.
int computeDamage(const Fighter& attacker, const Fighter& defender, const Move& move, bool crit);

//FUNCTION TO APPLY A MOVE FROM ONE FIGHTER TO ANOTHER
void applyMove(Fighter* user, Fighter* target, Move* move, RNG& rng);

#endif
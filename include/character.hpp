#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <string>
#include <random>

//MOVEKIND IS AN ENUM CLASS THAT DEFINES THE KIND OF MOVE, WHETHER IT BE AN ATTACK, HEAL OR DEFEND
enum class MoveKind {Attack, Heal, Defend};

//MOVE STRUCTURE DEFINES THE NAME OF THE MOVE, ITS KIND, POWER, ACCURACY AND CRIT CHANCE
struct Move {
	std::string name;
	MoveKind kind;
	int power;
	int accuracy; // 0-100
	int critChance; // 0-100 (only used for Attack)
};

//FIGHTER STRUCTURE DEFINES THE NAME, CLASSNAME, HP, ATK, DEF, SPD, A TEMPORARY DEFENSE BUFF, AN ARRAY OF MOVES, AND THE LAST MOVE USED
struct Fighter {
	std::string name;
	std::string className;

	int maxHP;
	int hp;
	int atk;
	int def;
	int spd;
	int defBuff;
	Move moves[4];
	int lastMove;

};

//RNG STRUCT FOR RANDOM NUMBER GENERATION
struct RNG {

	std::mt19937 gen;
	RNG() : gen(std::random_device{}()) {}

	int rollInt(int lo, int hi) {
		std::uniform_int_distribution<int> dist(lo, hi);
		return dist(gen);
	}

	bool chance(int percent) { // percent 0..100
		if (percent <= 0) return false;
		if (percent >= 100) return true;
		return rollInt(1, 100) <= percent;
	}

};

//IF THE PLAYER CHOOSES THE WARRIOR CLASS
Fighter warrior(const std::string& playerName);

//IF THE PLAYER CHOOSES THE MAGE CLASS
Fighter mage(const std::string& playerName);

//IF THE PLAYER CHOOSES THE HUNTER CLASS
Fighter hunter(const std::string& playerName);

//WARRIOR ENEMIES
Fighter goblin();
Fighter ogre();
//MAGE ENEMIES
Fighter zombie();
Fighter minotaur();
//HUNTER ENEMIES
Fighter wolf();
Fighter demonSpawn();
//FINAL BOSS FOR ALL CLASSES
Fighter dragon();

//FUNCTION TO PROMPT THE USER TO SELECT A CHARACTER
int charSelect();

#endif
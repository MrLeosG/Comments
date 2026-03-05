#pragma once

//Health pool that will be altered based on enemy/type
int enemy_health = 10;
constexpr int max_hp = 10;

//Weapon damage that can be multiplied
constexpr int leaf_blade = 5;
constexpr int infernal_wand = 5;
constexpr int aquatic_shield = 5;

//damage
constexpr int damage = 2;
int damage_taken;

void equipment();

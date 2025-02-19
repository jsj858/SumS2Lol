#include "pch.h"
#include "Goblin.h"
#include "CreatureManager.h"

Goblin::Goblin(string name, int hp, int atk, int specialAttackCooldown)
	:Monster(name, hp, atk, specialAttackCooldown)
{
}

Goblin::~Goblin()
{
}

void Goblin::SpecialAttack(Creature* other)
{
	CreatureManager::Get().GetRandomPlayer()->TakeDamage(this, (_attack * 2));
}

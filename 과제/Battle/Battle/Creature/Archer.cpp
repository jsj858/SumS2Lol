#include "pch.h"
#include "Archer.h"
#include "Player.h"
#include "CreatureManager.h"

Archer::Archer(string name, int hp, int atk, int specialAttackCooldown, int mp)
	:Player(name, hp, atk, specialAttackCooldown, mp)
{
}

Archer::~Archer()
{
}

void Archer::SpecialAttack(Creature* other)
{
	CreatureManager::Get().GetRandomMonster()->TakeDamage(this, _attack * 2);
}

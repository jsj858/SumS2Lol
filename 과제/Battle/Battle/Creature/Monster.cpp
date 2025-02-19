#include "pch.h"
#include "Monster.h"
#include "Creature.h"
#include "CreatureManager.h"

Monster::Monster(string name, int hp, int atk, int specialAttackCooldown)
	:Creature(name, hp, atk, specialAttackCooldown)
{
}

Monster::~Monster()
{
}

void Monster::Onturn()
{
	_specialAttackCooldown--;

	if (_specialAttackCooldown <= 0)
	{
		SpecialAttack(CreatureManager::Get().GetRandomPlayer());
		_specialAttackCooldown = 5;
	}
	else
	{
		Attack(CreatureManager::Get().GetRandomPlayer());
	}
}

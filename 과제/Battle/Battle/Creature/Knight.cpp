#include "pch.h"
#include "Knight.h"
#include "Player.h"
#include "CreatureManager.h"

Knight::Knight(string name, int hp, int atk, int specialAttackCooldown, int mp)
	:Player(name, hp, atk, specialAttackCooldown ,mp)
{
}

Knight::~Knight()
{
}

void Knight::SpecialAttack(Creature* other)
{
	CreatureManager::Get().GetRandomMonster()->TakeDamage(this, (_attack * 2));
}

#include "pch.h"
#include "Wizard.h"
#include "Player.h"
#include "CreatureManager.h"

Wizard::Wizard(string name, int hp, int atk, int specialAttackCooldown, int mp)
	:Player(name, hp, atk, specialAttackCooldown, mp)
{
}

Wizard::~Wizard()
{
}

void Wizard::SpecialAttack(Creature* other)
{
	CreatureManager::Get().GetRandomMonster()->TakeDamage(this, _attack * 2);
}

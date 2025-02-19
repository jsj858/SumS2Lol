#include "pch.h"
#include "Player.h"
#include "Creature.h"
#include "CreatureManager.h"

Player::Player(string name, int hp, int atk, int specialAttackCooldown, int mp)
	:Creature(name, hp, atk, specialAttackCooldown), _mp(mp)
{
}

Player::~Player()
{
}

void Player::ShowInfo()
{
	Creature::ShowInfo();
	cout << "MP       : " << _mp << endl;
}

void Player::Onturn()
{
	_specialAttackCooldown--;

	if (_specialAttackCooldown <= 0 && _mp > 0)
	{
		SpecialAttack(CreatureManager::Get().GetRandomMonster());
		_specialAttackCooldown = 3;
		_mp--;
		if (_mp < 0)
		{
			_mp = 0;
		}
	}
	else
	{
		Attack(CreatureManager::Get().GetRandomMonster());
	}
}


#include "pch.h"
#include "BossMonster.h"
#include "Monster.h"

BossMonster::BossMonster(string name, int hp, int atk, int specialAttackCooldown)
	:Monster(name, hp, atk, specialAttackCooldown)
{
}

BossMonster::~BossMonster()
{
}

void BossMonster::Onturn()
{
	_specialAttackCooldown--;

	for (unordered_map<Creature*, int>::iterator i = aggro.begin(); i != aggro.end();)
	{
		if (i->first->IsDead())
		{
			i = aggro.erase(i);
		}
		else
		{
			i++;
		}
	}

	vector<pair<Creature*, int>> sortMap(aggro.begin(), aggro.end());

	std::partial_sort(sortMap.begin(), sortMap.begin() + std::min(4, static_cast<int>(sortMap.size())), sortMap.end(), [](const pair<Creature*, int>& first, const pair<Creature*, int>& second)
		{return first.second > second.second; });

	for (int i = 0; i < std::min(4, static_cast<int>(sortMap.size())); i++)
	{
		if (_specialAttackCooldown <= 0)
		{
			SpecialAttack(sortMap[i].first);
			_specialAttackCooldown = 5;
		}
		else
		{
			Attack(sortMap[i].first);
		}
	}

	
}

void BossMonster::TakeDamage(Creature* other, int damage)
{
	_hp -= damage;

	if (aggro.count(other))
	{
		aggro[other] += damage;
	}
	else
	{
		aggro.insert({ other, damage });
	}

	if (_hp <= 0)
	{
		_hp = 0;
		_isDead = true;
	}
}

void BossMonster::SpecialAttack(Creature* other)
{
	other->TakeDamage(this, (_attack * 3));
}

#include "pch.h"
#include "CreatureManager.h"
#include "Creature\Creature.h"

CreatureManager::CreatureManager()
{
}

CreatureManager::~CreatureManager()
{
	for (Creature* creature : creatures)
	{
		delete creature;
		creature = nullptr;
	}
}

void CreatureManager::AddCreature(Creature* creature)
{
	creatures.push_back(creature);
}

void CreatureManager::DeleteCreature()
{
	auto iter = std::remove_if(creatures.begin(), creatures.end(), [](Creature* creature)
		{
			if (creature->IsDead())
			{
				delete creature;
				return true;
			}
			return false;
		});

	creatures.erase(iter, creatures.end());
}

Creature* CreatureManager::GetRandomMonster()
{
	vector<Creature*>monsters;

	for (Creature* creature : creatures)
	{
		if (creature->IsMonster())
		{
			monsters.push_back(creature);
		}
	}

	int randomMonster = rand() % monsters.size();


	return monsters[randomMonster];
}

Creature* CreatureManager::GetRandomPlayer()
{
	vector<Creature*>players;

	for (Creature* creature : creatures)
	{
		if (creature->IsPlayer())
		{
			players.push_back(creature);
		}
	}

	int randomMonster = rand() % players.size();


	return players[randomMonster];
}

vector<Creature*> CreatureManager::GetAllPlayer()
{
	vector<Creature*>players;

	for (Creature* creature : creatures)
	{
		if (creature->IsPlayer())
		{
			players.push_back(creature);
		}
	}

	return players;
}

vector<Creature*> CreatureManager::GetAllMonster()
{
	vector<Creature*>monsters;

	for (Creature* creature : creatures)
	{
		if (creature->IsMonster())
		{
			monsters.push_back(creature);
		}
	}

	return monsters;
}
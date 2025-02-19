#pragma once
#include "Creature/Creature.h"

class Monster : public Creature
{
public:
	Monster(string name, int hp, int atk, int specialAttackCooldown);
	~Monster();

	virtual void Onturn() override;
	virtual bool IsMonster() override { return true; }

private:

};

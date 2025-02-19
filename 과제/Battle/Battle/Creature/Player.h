#pragma once
#include "Creature/Creature.h"

class Player : public Creature
{
public:
	Player(string name, int hp, int atk, int specialAttackCooldown, int mp = 100);
	~Player();

	virtual void ShowInfo() override;
	virtual void Onturn() override;

	virtual bool IsPlayer() override { return true; }

private:
	int _mp;
};

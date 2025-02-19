#pragma once
#include "Creature/Monster.h"

class Goblin : public Monster
{
public:
	Goblin(string name = "Goblin", int hp = 30, int atk = 5, int specialAttackCooldown = 5);
	~Goblin();

private:
	virtual void SpecialAttack(Creature* other) override;

};

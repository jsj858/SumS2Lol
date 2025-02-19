#pragma once
#include "Creature/Player.h"

class Archer : public Player
{
public:
	Archer(string name, int hp, int atk, int specialAttackCooldown = 3, int mp = 10);
	~Archer();

	virtual void SpecialAttack(Creature* other) override;

private:

};

#pragma once
#include "Creature/Player.h"

class Knight : public Player
{
public:
	Knight(string name, int hp, int atk, int specialAttackCooldown = 3, int mp = 10);
	~Knight();

	virtual void SpecialAttack(Creature* other) override;

private:

};

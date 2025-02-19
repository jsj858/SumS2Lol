#pragma once
#include "Creature/Player.h"

class Wizard : public Player
{
public:
	Wizard(string name, int hp, int atk, int specialAttackCooldown = 0, int mp = 15);
	~Wizard();

	virtual void SpecialAttack(Creature* other) override;

private:

};

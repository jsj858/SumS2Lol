#pragma once
#include "Creature/Monster.h"

class BossMonster : public Monster
{
public:
	BossMonster(string name = "Boss", int hp = 1000, int atk = 30, int specialAttackCooldown = 5);
	~BossMonster();

	virtual void Onturn() override;
	virtual void TakeDamage(Creature* other, int damage) override;

private:
	virtual void SpecialAttack(Creature* other) override;

private:
	unordered_map<Creature*, int> aggro;
};

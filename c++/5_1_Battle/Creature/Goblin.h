#pragma once
#include "Monster.h"
class Knight;

class Goblin : public Monster
{
public:
	Goblin();
	Goblin(int hp, int atk, string name);
	~Goblin();

	virtual void Attack(Creature* other) override;

	void DeadSound();

private:
	// private 멤버변수에 접근할 수 있는 얘 : 멤버함수
};


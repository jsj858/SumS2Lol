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
	// private ��������� ������ �� �ִ� �� : ����Լ�
};


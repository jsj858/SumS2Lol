#include "pch.h"

#include <string>

#include "Creature/Player.h"
#include "Creature/Creature.h"
#include "Creature/Knight.h"
#include "Creature/Goblin.h"

// sln : solution
// - 서점
// 
// proj : project
// - 구역

// 과제 1.
// - Player가 Knight, Mage, Archer 중 하나 선택
// - Player와 Goblin과 죽을 때 까지 전투

// Extra
// - Player가 Knight, Mage, Archer 중 하나 선택
// - Goblin 배열로 10마리
// - Player 1 vs Goblin 10
// - 고블린이 전부 죽거나, Player가 죽으면 게임 끝

bool IsAllDead(Goblin* arr[], int size)
{
	bool allDead = true;

	for (int i = 0; i < size; i++)
	{
		if (arr[i]->IsDead() == false)
			return false;
	}

	return allDead;
}

int main()
{
	Knight* k = new Knight(100, 13, "ha1");

	Goblin* goblins[10] = {};
	for (int i = 0; i < 10; i++)
	{
		goblins[i] = new Goblin();
	}

	for (int i = 0; i < 10; i++)
	{
		goblins[i]->SetName("Goblin" + to_string(i));
	}

	while (true)
	{
		// k가 죽거나 
		if (k->IsDead())
			break;
		// 모든 고블린 사망
		if (IsAllDead(goblins, 10))
			break;

		for (int i = 0; i < 10; i++)
		{
			k->Attack(goblins[i]);
			goblins[i]->Attack(k);
		}
	}

	delete k;
	for (int i = 0; i < 10; i++)
	{
		delete goblins[i];
	}

	return 0;
}
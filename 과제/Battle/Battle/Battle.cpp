#include "pch.h"
#include "Creature/Creature.h"
#include "Creature/Player.h"
#include "Creature/Knight.h"
#include "Creature/Archer.h"
#include "Creature/Wizard.h"
#include "Creature/Monster.h"
#include "Creature/Goblin.h"
#include "Creature/BossMonster.h"
#include "CreatureManager.h"


//싱글턴 만들기
int main()
{
	srand(time(NULL));

	CreatureManager::Get().AddCreature(new Knight("Knight1", 100, 15));
	CreatureManager::Get().AddCreature(new Knight("Knight2", 100, 15));
	CreatureManager::Get().AddCreature(new Knight("Knight3", 100, 15));
	CreatureManager::Get().AddCreature(new Knight("Knight4", 100, 15));
	CreatureManager::Get().AddCreature(new Archer("Archer1", 100, 10));
	CreatureManager::Get().AddCreature(new Archer("Archer2", 100, 10));
	CreatureManager::Get().AddCreature(new Archer("Archer3", 100, 10));
	CreatureManager::Get().AddCreature(new Wizard("Wizard1", 100, 5));
	CreatureManager::Get().AddCreature(new Wizard("Wizard2", 100, 5));
	CreatureManager::Get().AddCreature(new Wizard("Wizard3", 100, 5));

	
	//CreatureManager::Get().AddCreature(new Goblin("goblin1"));
	//CreatureManager::Get().AddCreature(new Goblin("goblin2"));
	CreatureManager::Get().AddCreature(new BossMonster());

	while (true)
	{
		vector<Creature*>players = CreatureManager::Get().GetAllPlayer();
		vector<Creature*>monsters = CreatureManager::Get().GetAllMonster();
		for (Creature* player : players)
		{
			player->Onturn();
		}

		if (std::all_of(players.begin(), players.end(), [](Creature* player) {return player->IsDead(); }))
		{
			for (Creature* player : players)
			{
				player->ShowInfo();
			}
			for (Creature* monster : monsters)
			{
				monster->ShowInfo();
			}
			
			return 0;
		}

   		for (Creature* monster : monsters)
		{
			monster->Onturn();
		}

		if (std::all_of(monsters.begin(), monsters.end(), [](Creature* monster) {return monster->IsDead(); }))
		{
			for (Creature * player : players)
			{
				player->ShowInfo();
			}
			for (Creature* monster : monsters)
			{
				monster->ShowInfo();
			}

			return 0;
		}

		CreatureManager::Get().DeleteCreature();


		
	}
		

	//Creature* goblin1 = new Goblin();
	//Creature* goblin2 = new Goblin();
	//Creature* goblin3 = new Goblin();
	//Creature* goblin4 = new Goblin();
	//Creature* boss = new BossMonster();

	//player1->Onturn(boss);
	//player2->Onturn(boss);
	//player3->Onturn(boss);
	//goblin1->Onturn(boss);
	//goblin2->Onturn(boss);

	//player1->ShowInfo();
	//player2->ShowInfo();
	//player3->ShowInfo();
	//goblin1->ShowInfo();
	//goblin2->ShowInfo();
	//boss->ShowInfo();
	//

	return 0;
}

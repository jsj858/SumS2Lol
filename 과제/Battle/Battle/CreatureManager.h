#pragma once

class Creature;

class CreatureManager
{
private:
	CreatureManager();
	~CreatureManager();
	CreatureManager(const CreatureManager&) = delete;
	CreatureManager& operator=(const CreatureManager&) = delete;
public:
	static CreatureManager& Get() { static CreatureManager instance; return instance; }

	void AddCreature(Creature* creature);
	void DeleteCreature();

	Creature* GetRandomMonster();
	Creature* GetRandomPlayer();
	vector<Creature*> GetAllPlayer();
	vector<Creature*> GetAllMonster();

private:
	vector<Creature*> creatures;
};

#pragma once

class Creature
{
public:
	Creature(string name, int hp, int attack, int specialAttackCooldown = 2);
	virtual ~Creature();

	virtual void Onturn();
	virtual void TakeDamage(Creature* other, int damage);
	virtual void ShowInfo();

	bool IsDead() const { return _isDead; }

	virtual bool IsPlayer() { return false; }
	virtual bool IsMonster() { return false; }
protected:
	void Attack(Creature* other);
	virtual void SpecialAttack(Creature* other) = 0;

protected:
	string _name;
	int _hp;
	int _attack;
	int _specialAttackCooldown;
	bool _isDead;

};

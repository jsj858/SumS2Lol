#include "pch.h"
#include "Creature.h"

Creature::Creature(string name, int hp, int attack, int specialAttackCooldown)
	:_name(name), _hp(hp), _attack(attack), _specialAttackCooldown(specialAttackCooldown), _isDead(false)
{
}

Creature::~Creature()
{
}

void Creature::Attack(Creature* other)
{
	other->TakeDamage(this, _attack);
}

void Creature::Onturn()
{
	_specialAttackCooldown--;
	
	if (_specialAttackCooldown < 0)
		_specialAttackCooldown;
}

void Creature::TakeDamage(Creature* other, int damage)
{
	_hp -= damage;

	if (_hp <= 0)
	{
		_hp = 0;
		_isDead = true;
	}
}

void Creature::ShowInfo()
{
	cout << "-------------Info-------------" << endl;
	cout << "NAME     : "<< _name << endl;
	cout << "HP       : "<< _hp << endl;
	cout << "ATK      : "<< _attack << endl;
	cout << "COOLDOWN : "<< _specialAttackCooldown << endl;
	cout << "ISDEAD   : "<< _isDead << endl;
}


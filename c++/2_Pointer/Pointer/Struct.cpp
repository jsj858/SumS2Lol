#include <iostream>

using namespace std;

// . : ���������
// -> : ������������� ( * .)

struct Player
{
	// ��� ����
	string name;
	int hp;
	int atk;
};

// ������ �б�����
void PrintPlayer(const Player* const p)
{
	cout << "NAME : " << p->name << endl;
	cout << "HP : " << p->hp << endl;
	cout << "ATK : " << p->atk << endl;
}

void SetPlayer(Player* p, string name, int hp, int atk)
{
	p->name = name;
	p->hp = hp;
	(*p).atk = atk;
}

void Attack(Player* attacker, Player* victim)
{
	victim->hp -= attacker->atk;
	cout << attacker->name << "�� " << victim->name << "�� " << attacker->atk << "��ŭ �����߽��ϴ�!!!" << endl;
}

int main()
{
	Player p1;
	p1.hp = 0;
	p1.atk = 0;

	Player p2;
	p2.hp = 0;
	p2.atk = 0;

	SetPlayer(&p1, "Hanil1", 100, 5);
	SetPlayer(&p2, "Hanil2", 150, 13);

	Attack(&p1, &p2);

	PrintPlayer(&p1);
	PrintPlayer(&p2);
	

	return 0;
}
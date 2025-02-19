#include <iostream>

using namespace std;

// . : 멤버연산자
// -> : 간접멤버연산자 ( * .)

struct Player
{
	// 멤버 변수
	string name;
	int hp;
	int atk;
};

// 포인터 읽기전용
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
	cout << attacker->name << "이 " << victim->name << "을 " << attacker->atk << "만큼 공격했습니다!!!" << endl;
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
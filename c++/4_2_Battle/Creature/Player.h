#pragma once

// h�� �����
// h, cpp ����
// => ��Ŀ

// ���漱��
class Creature;
// #include �� ���� �ʴ� ����

class Player : public Creature
{
public:
	Player(int hp, int atk, string name);
	~Player();


protected:
	string _name;
};

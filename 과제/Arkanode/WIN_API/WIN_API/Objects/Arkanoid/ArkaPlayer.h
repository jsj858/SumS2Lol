#pragma once

class ArkaPlayer
{
public:
	ArkaPlayer();
	~ArkaPlayer();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _pos = pos; }
	Vector GetPos() { return _pos; }
	shared_ptr<RectCollider> GetCollider() { return _player; }

	int GetHp() { return _hp; }
	void SetHp(int hp) { _hp = hp; }
private:

	int _hp;

	shared_ptr<RectCollider> _player;

	Vector _pos;
};

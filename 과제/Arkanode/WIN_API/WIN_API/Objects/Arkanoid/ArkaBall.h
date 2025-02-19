#pragma once

class ArkaPlayer;
class ArkanoidBlock;

class ArkaBall
{
public:
	ArkaBall(shared_ptr<ArkaPlayer> player);
	~ArkaBall();

	void Update();
	void Render(HDC hdc);

	void Fixed();

	void SetPos(Vector pos) { _pos = pos; }
	Vector GetPos() { return _pos; }

	void SetDir(Vector dir) { _dir = dir.NormalVector(); }
	Vector GetDir() { return _dir; }

	void IsActive(bool b) { _isActive = b; }
	bool IsActive() { return _isActive; }

	void IsFire(bool b) { _isFired = b; }
	bool IsFire() { return _isFired; }

	shared_ptr<CircleCollider> GetCollider() { return _ball; }


private:
	shared_ptr<CircleCollider> _ball;
	weak_ptr<ArkaPlayer> _player;

	Vector _pos = { 0,0 };
	Vector _dir = { 0,0 };
	float _speed = 7.0f;

	bool _isFired = false;
	bool _isActive = true;
};

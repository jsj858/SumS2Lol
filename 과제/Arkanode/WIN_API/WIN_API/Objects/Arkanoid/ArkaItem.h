#pragma once

class ArkanoidBlock;

class ArkaItem
{
public:
	ArkaItem(shared_ptr<ArkanoidBlock> block);
	~ArkaItem();

	void Update();
	void Render(HDC hdc);

	void StartFalling() { _canFalling = true; }

	void SetPos(Vector pos) { _pos = pos; }

	void IsActive(bool b) { _isActive = b; }

	shared_ptr<CircleCollider> GetCollider() { return _body; }

private:
	shared_ptr<CircleCollider> _body;

	bool _canFalling = false;
	bool _isActive = true;

	Vector _pos = { 0,0 };
	Vector _dir = { 0,1 };
	float _speed = 4.0f;
};

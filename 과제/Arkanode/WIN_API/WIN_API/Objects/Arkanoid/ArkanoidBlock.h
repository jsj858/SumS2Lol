#pragma once

class ArkaItem;

class ArkanoidBlock
{
public:
	ArkanoidBlock(Vector size);
	~ArkanoidBlock();

	shared_ptr<RectCollider> GetBodt() { return _body; }

	void Update();
	void Render(HDC hdc);

	void BreakBrick();

	void SetItem(shared_ptr<ArkaItem> item);

	void SetPos(Vector pos) { _pos = pos; }
	Vector GetPos() { return _pos; }

	bool IsActive() { return _isActive; }
	void IsActive(bool b) { _isActive = b; }

	shared_ptr<RectCollider> GetCollider() { return _body; }

private:
	bool _isActive = false;

	shared_ptr<RectCollider> _body;
	Vector _pos;

	weak_ptr<ArkaItem> _item;
};

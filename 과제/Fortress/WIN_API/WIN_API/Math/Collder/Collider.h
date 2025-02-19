#pragma once

class RectCollider;
class CircleCollider;

class Collider
{
public:
	Collider(Vector center);
	~Collider();

	virtual void Update() = 0;
	virtual void Render(HDC hdc);

	Vector GetCenter() { return _center; }
	void SetCenter(const Vector& pos) { _center = pos; }

	void SetGreen() { _curPen = 0; }
	void SetRed() { _curPen = 1; }

	virtual bool IsCollision(const Vector& pos) = 0;
	virtual bool IsCollision(shared_ptr<RectCollider> other) = 0;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) = 0;
	virtual bool IsCollision(shared_ptr<Collider> other)  = 0;
protected:
	UINT _curPen = 0;
	vector<HPEN> _pens;

	Vector _center;
};

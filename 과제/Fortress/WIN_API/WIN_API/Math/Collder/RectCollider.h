#pragma once

class RectCollider : public Collider
{
public:
	RectCollider(Vector center, Vector size);
	~RectCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	// Vector GetCenter() { return _center; }
	// void SetCenter(const Vector& pos) { _center = pos; }

	// void SetGreen() { _curPen = 0; }
	// void SetRed() { _curPen = 1; }

	virtual bool IsCollision(const Vector& pos) override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<Collider> other) override;

	float Left() { return _center.x - _halfSize.x; }
	float Right() { return _center.x + _halfSize.x; }
	float Top() { return _center.y - _halfSize.y; }
	float Bottom() { return _center.y + _halfSize.y; }

private:
	// UINT _curPen = 0;
	// vector<HPEN> _pens;

	// Vector _center;
	Vector _halfSize;
};

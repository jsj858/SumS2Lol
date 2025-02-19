#pragma once

class RectCollider;

class CircleCollider : public Collider, public enable_shared_from_this<CircleCollider>
{
public:
	CircleCollider(Vector center, float radius);
	~CircleCollider();

	void Update();
	void Render(HDC hdc);

	// Vector GetCenter() { return _center; }
	// void SetCenter(const Vector& pos) { _center = pos; }

	// void SetGreen() { _curPen = 0; }
	// void SetRed() { _curPen = 1; }

	virtual bool IsCollision(const Vector& pos) override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) override;
	virtual bool IsCollision(shared_ptr<Collider> other) override;

	float GetRadius() { return _radius; }
	void SetRadius(float radius) { _radius = radius; }

private:
	// UINT _curPen = 0;
	// vector<HPEN> _pens;

	// Vector _center;
	float _radius;
};

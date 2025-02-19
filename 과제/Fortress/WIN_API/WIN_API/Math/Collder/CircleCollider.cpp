#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	:Collider(center), _radius(radius)
{
	// _pens.push_back(CreatePen(1, 3, GREEN));
	// _pens.push_back(CreatePen(1, 3, RED));
}

CircleCollider::~CircleCollider()
{
	// for (auto pen : _pens)
	// {
	// 	DeleteObject(pen);
	// }
}

void CircleCollider::Update()
{
	
}

void CircleCollider::Render(HDC hdc)
{
	//SelectObject(hdc, _pens[_curPen]);
	Collider::Render(hdc);

	float left = _center.x - _radius;
	float right = _center.x + _radius;
	float top = _center.y - _radius;
	float bottom = _center.y + _radius;

	Ellipse(hdc, left, top, right, bottom);
}

bool CircleCollider::IsCollision(const Vector& pos)
{
	Vector circleCenter = GetCenter();
	Vector direction = pos - circleCenter;

	return direction.Length() < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	Vector circleCentor_1 = GetCenter();
	Vector circleCentor_2 = other->GetCenter();
	Vector direction = (circleCentor_2 - circleCentor_1);


	return direction.Length() < _radius + other->_radius;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	//Vector pos;

	//pos.x = min(max(other->Left(), GetCenter().x), other->Right());
	//pos.y = min(max(other->Top(), GetCenter().y), other->Bottom());

	//return IsCollision(pos);

	return other->IsCollision(shared_from_this());
}

bool CircleCollider::IsCollision(shared_ptr<Collider> other)
{
	shared_ptr<RectCollider> rect = dynamic_pointer_cast<RectCollider>(other);
	if (rect == nullptr)
	{
		shared_ptr<CircleCollider> circle = dynamic_pointer_cast<CircleCollider>(other);

		return IsCollision(circle);
	}

	return IsCollision(rect);
}
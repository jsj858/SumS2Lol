#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
	:Collider(center), _halfSize(size * 0.5f)
{
	// _pens.push_back(CreatePen(1, 3, GREEN));
	// _pens.push_back(CreatePen(1, 3, RED));
}

RectCollider::~RectCollider()
{
	// for (auto pen : _pens)
	// {
	// 	DeleteObject(pen);
	// }
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	//SelectObject(hdc, _pens[_curPen]);
	Collider::Render(hdc);

	Rectangle(hdc, Left(), Top(), Right(), Bottom());
}

// rect  회전하지 않는다는 조건
bool RectCollider::IsCollision(const Vector& pos)
{
		if (pos.x > Left() && pos.x < Right() && pos.y > Top() && pos.y < Bottom())
		return true;

	return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	//if (other->Left() < Right() && other->Top() < Bottom() && other->Bottom() > Top() && other->Right() > Left())
		//return true;
	
	if (other->Left() > Right())
		return false;
	if (other->Right() < Left())
		return false;
	if (other->Top() > Bottom())
		return false;
	if (other->Bottom() < Top())
		return false;

	return true;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	/*Vector pos;

	pos.x = min(max(Left(), other->GetCenter().x), Right());
	pos.y = min(max(Top(), other->GetCenter().y), Bottom());

	Vector direction = other->GetCenter() - pos;
	
	return direction.Length() <= other->GetRadius();*/

	Vector dir = other->GetCenter() - GetCenter();
	Vector rightV = Vector(1, 0);
	Vector upV = Vector(0, -1);

	// 예외처리
	float length = dir.Length();
	float rectHalfLength = _halfSize.Length();
	float circleRadius = other->GetRadius();

	if (length > rectHalfLength + circleRadius)
		return false;

	// x축 내적
	float lenghtX = abs(rightV.Dot(dir));
	if (lenghtX > _halfSize.x + circleRadius)
		return false;

	// y축 내적
	float lengthY = abs(upV.Dot(dir));
	if (lengthY > _halfSize.y + circleRadius)
		return false;

	return true;
}

bool RectCollider::IsCollision(shared_ptr<Collider> other)
{
	shared_ptr<RectCollider> rect = dynamic_pointer_cast<RectCollider>(other);
	if (rect == nullptr)
	{
		shared_ptr<CircleCollider> circle= dynamic_pointer_cast<CircleCollider>(other);
		
		return IsCollision(circle);
	}

	return IsCollision(rect);

}
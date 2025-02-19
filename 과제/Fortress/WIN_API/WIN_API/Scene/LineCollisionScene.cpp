#include "framework.h"
#include "LineCollisionScene.h"

LineCollisionScene::LineCollisionScene()
{
	_line1 = make_shared<Line>(Vector(100, 100), Vector(100, 100));
	_line2 = make_shared<Line>(Vector(100, 500), Vector(700, 200));

	_hitPoint = make_shared<CircleCollider>(Vector(100, 100), 6);
	_hitPoint->SetRed();
}

LineCollisionScene::~LineCollisionScene()
{
}

void LineCollisionScene::Update()
{
	_line1->Update();
	_line2->Update();
	_hitPoint->Update();

	Line::HitResult hitResult = _line1->IsCollision(_line2);
	if (hitResult.isCollision)
	{
		/*Vector v1 = {_line1->end.x - _line1->start.x, _line1->end.y - _line1->start.y};
		Vector v2 = { _line2->end.x - _line2->start.x, _line2->end.y - _line2->start.y };

		float det = v1.Cross(v2);

		float t = ((_line2->start.x - _line1->start.x) * v2.y - (_line2->start.y - _line1->start.y) * v2.x) / det;

		_circle->SetCenter({ (_line1->start.x + t * v1.x), (_line1->start.y + t * v1.y) });*/

		_line2->SetRed();
		_hitPoint->SetCenter(hitResult.hitPoint);
	}
	else
	{
		_line2->SetGreen();
	}

	_line1->end = mousePos;
}

void LineCollisionScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_hitPoint->Render(hdc);
}

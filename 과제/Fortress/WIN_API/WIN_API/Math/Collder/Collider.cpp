#include "framework.h"
#include "Collider.h"

Collider::Collider(Vector center)
	:_center(center)
{
	_pens.push_back(CreatePen(1, 3, GREEN));
	_pens.push_back(CreatePen(1, 3, RED));
}

Collider::~Collider()
{
	for (auto pen : _pens)
	{
		DeleteObject(pen);
	}
}

void Collider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_curPen]);
}

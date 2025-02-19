#include "framework.h"
#include "ArkaItem.h"

#include "Objects/Arkanoid/ArkanoidBlock.h"

ArkaItem::ArkaItem(shared_ptr<ArkanoidBlock> block)
{
	_body = make_shared<CircleCollider>(_pos, 5.0f);
	_pos = block->GetPos();
}

ArkaItem::~ArkaItem()
{
}

void ArkaItem::Update()
{
	if (_isActive == false)
		return;

	_body->Update();

	_body->SetCenter(_pos);

	if (_canFalling)
		_pos += _dir * _speed;
}

void ArkaItem::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	_body->Render(hdc);
}

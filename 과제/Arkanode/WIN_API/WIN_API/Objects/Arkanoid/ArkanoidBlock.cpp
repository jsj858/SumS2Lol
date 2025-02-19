#include "framework.h"
#include "ArkanoidBlock.h"
#include "Objects/Arkanoid/ArkaItem.h"

ArkanoidBlock::ArkanoidBlock(Vector size)
{
	_pos = CENTER;
	_body = make_shared<RectCollider>(CENTER, size);
}

ArkanoidBlock::~ArkanoidBlock()
{
}

void ArkanoidBlock::Update()
{
	if (!_isActive)
		return;

	_body->Update();

	_body->SetCenter(_pos);
}

void ArkanoidBlock::Render(HDC hdc)
{
	if (_isActive)
		_body->Render(hdc);
}

void ArkanoidBlock::BreakBrick()
{
	_isActive = false;
	if (!_item.expired())
		_item.lock()->StartFalling();
}

void ArkanoidBlock::SetItem(shared_ptr<ArkaItem> item)
{
	_item = item;
	if (_item.expired())
		return;

	_item.lock()->SetPos(_pos);
}

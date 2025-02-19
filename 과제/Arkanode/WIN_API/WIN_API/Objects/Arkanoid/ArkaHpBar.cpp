#include "framework.h"
#include "ArkaHpBar.h"

ArkaHpBar::ArkaHpBar(Vector center, Vector size)
{
	_bg = make_shared<RectCollider>(center, size);
	_value = make_shared<RectCollider>(center, size);

	_redBrush = CreateSolidBrush(RGB(255, 0, 0));
	_oldBrush = CreateSolidBrush(RGB(255, 255, 255));
}

ArkaHpBar::~ArkaHpBar()
{
	DeleteObject(_redBrush);
	DeleteObject(_oldBrush);
}

void ArkaHpBar::Update()
{
	_bg->Update();
	_value->Update();
}

void ArkaHpBar::Render(HDC hdc)
{
	_bg->Render(hdc);

	SelectObject(hdc, _redBrush);
	_value->Render(hdc);
	SelectObject(hdc, _oldBrush);
}

void ArkaHpBar::SetValue(float value)
{
	Vector bg = _bg->GetSize();
	Vector hp = bg;
	hp.x = bg.x * value;

	_value->SetSize(hp);

	// center
	float left = _bg->Left();
	float centerX = left + _value->GetHalfSize().x;
	float centerY = _value->GetCenter().y;
	_value->SetCenter(Vector(centerX, centerY));
}

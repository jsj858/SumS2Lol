#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_circle = make_shared<CircleCollider>(Vector(-1000, -1000), 10);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	if (isActive == false) return;

	_circle->Update();
	_ballHasGone += _dir.Length();

#pragma region ���ڿ
	// ���ڿ
	// sin(theta)
	Vector goV;
	// cos(a+b) = cos(a) * cos(b) - sin(a) * sin(b)
	// x' = _ballSasGone * _dir.x - sinf(_ballHasGone) * _dir.y;
	// sin(a+b) = sin(a) * cos(b) + cos(a) * sin(b)
	// y' = sinf(_ballHasGone) * _dir.x + _ballHasGone * _dir.y;

	// Normalize : ����ȭ => ���̰� 1�� ���� => ���⸸ �����ִ� �� => ����
	// NormalVector : ��������
	// acos(theta) : cos�� ���Լ�
	// asin(theta) : sin�� ���Լ�
	// atan(theta) : tan�� ���Լ�
	// # atan(tan(theta)) = theta
	// f x f^-1(x) = x

	//goV.x = 1 * _dir.x - sinf(_ballHasGone) * _dir.y * 10;
	//goV.y = sinf(_ballHasGone) * _dir.x  * 10 + 1 * _dir.y;
#pragma endregion

#pragma region �����̻���
	// ����
	/*_dir;
	Vector guided = mousePos - _circle->GetCenter();
	float cross = _dir.Cross(guided);
	if (abs(cross) < 0.01)
	{
	}
	else if (cross < 0.0f)
	{
		_dir.Rotate(-0.1f);
	}
	else
	{
		_dir.Rotate(0.1f);
	}*/
#pragma endregion


	_circle->SetCenter(_circle->GetCenter() + _dir * _ballSpeed);

	// ȭ�� �� ������ ����ó��
	/*if (_circle->GetCenter().x > WIN_WIDTH || _circle->GetCenter().x < 0
		|| _circle->GetCenter().y > WIN_HEIGHT || _circle->GetCenter().y < 0)
	{
		isActive = false;
	}*/
	Vector center = _circle->GetCenter();
	if (center.x < 0 || center.x > WIN_WIDTH)
	{
		_dir.x *= -1;
	}
	if (center.y < 0 || center.y > WIN_HEIGHT)
	{
		_dir.y *= -1;
	}
}

void Ball::Render(HDC hdc)
{
	if (isActive == false) return;

	_circle->Render(hdc);
}

void Ball::Fire(Vector dir)
{
	_dir = dir.NormalVector();
	_ballHasGone = 0.0f;
}

void Ball::AddVector(Vector v)
{
	if (isActive == false) return;

	_circle->SetCenter(_circle->GetCenter() + v);
	_dir = v.NormalVector();
}

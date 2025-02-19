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
	if (IsActive == false)
		return;

	_circle->Update();

	if (_circle->GetCenter().x > WIN_WIDTH || _circle->GetCenter().x < 0 || _circle->GetCenter().y > WIN_HEIGHT || _circle->GetCenter().y < 0)
		IsActive = false;

	_gravityAccel += 0.1f;
}

void Ball::Render(HDC hdc)
{
	if (IsActive == false)
		return;

	_circle->Render(hdc);
}

void Ball::AddForce(float v)
{
	if (IsActive == false)
		return;

	_circle->SetCenter(_circle->GetCenter() + (_direction * v));

	// 유도
	//_direction = mousePos - _circle->GetCenter();
	//_circle->SetCenter(_circle->GetCenter() + (_direction.NormalVector() * v));

	// sin 그래프
	Vector perpendicular = Vector(-_direction.y, _direction.x);

	float t = _circle->GetCenter().Dot(_direction);
	float offset = _amplitude * sin(_frequency * t);

	_circle->SetCenter(_circle->GetCenter() + perpendicular * offset);

	// 중력
	// _circle->SetCenter(_circle->GetCenter() + _direction * v);
	// _circle->SetCenter(_circle->GetCenter() + Vector(0, 1) * (_gravity + _gravityAccel));

}

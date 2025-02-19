#include "framework.h"
#include "ArkaBall.h"
#include "Objects/Arkanoid/ArkaPlayer.h"

ArkaBall::ArkaBall(shared_ptr<ArkaPlayer> player)
{
	_ball = make_shared<CircleCollider>(Vector(0, 0), 10.0f);

	_player = player;
}

ArkaBall::~ArkaBall()
{
}

void ArkaBall::Update()
{
	if (_isActive == false)
		return;

	_ball->Update();

	_pos += _dir * _speed;
	_ball->SetCenter(_pos);

	Fixed();
}

void ArkaBall::Render(HDC hdc)
{
	if (_isActive == false)
		return;

	_ball->Render(hdc);
}

void ArkaBall::Fixed()
{
	if (_isFired == true)
		return;

	shared_ptr<ArkaPlayer> player = _player.lock();
	Vector playerPos = player->GetPos();
	Vector playerHalf = player->GetCollider()->GetHalfSize();

	_pos = playerPos + Vector(0, - playerHalf.y - 5.0f);
}


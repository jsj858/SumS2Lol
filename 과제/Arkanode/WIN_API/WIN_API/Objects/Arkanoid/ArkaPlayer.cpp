#include "framework.h"
#include "ArkaPlayer.h"

ArkaPlayer::ArkaPlayer()
{
	_pos = CENTER + Vector(0, 200);
	_player = make_shared<RectCollider>(_pos, Vector(140, 20));

	_hp = 100;
}

ArkaPlayer::~ArkaPlayer()
{
}

void ArkaPlayer::Update()
{
	_player->Update();
	_player->SetCenter(_pos);
}

void ArkaPlayer::Render(HDC hdc)
{
	_player->Render(hdc);
}



#include "framework.h"
#include "ArkaCollisionManager.h"

#include "Objects/Arkanoid/ArkaMap.h"
#include "Objects/Arkanoid/ArkaPlayer.h"
#include "Objects/Arkanoid/ArkaBall.h"
#include "Objects/Arkanoid/ArkanoidBlock.h"
#include "Objects/Arkanoid/ArkaItem.h"
#include "Objects/Arkanoid/ArkaHpBar.h"

ArkaCollisionManager::ArkaCollisionManager(shared_ptr<ArkaPlayer> player, shared_ptr<ArkaBall> ball, shared_ptr<ArkaMap> map, shared_ptr<ArkaItem> item, shared_ptr<ArkaHpBar> hpBar)
{
	_player = player;
	_ball = ball;
	_map = map;
	_item = item;
	_hpBar = hpBar;
}

ArkaCollisionManager::~ArkaCollisionManager()
{
}

void ArkaCollisionManager::Update()
{
	BallCollisionPlayer();
	BallCollisionWall();
	BallCollisionBrick();
	PlayerCollisionItem();
}

void ArkaCollisionManager::BallCollisionPlayer()
{
	if (_ball->GetCollider()->IsCollision(_player->GetCollider()))
	{
		Vector dir = _ball->GetPos() - _player->GetPos();

		_ball->SetDir(dir.NormalVector());
	}
}

void ArkaCollisionManager::BallCollisionWall()
{
	if (_ball->GetPos().x < 0 || _ball->GetPos().x > WIN_WIDTH)
	{
		Vector curDir = _ball->GetDir();
		curDir.x *= -1.0f;
		_ball->SetDir(curDir);
	}
	if (_ball->GetPos().y < 0)
	{
		Vector curDir = _ball->GetDir();
		curDir.y *= -1.0f;
		_ball->SetDir(curDir);
	}
	if (_ball->GetPos().y > WIN_HEIGHT)
	{
		if (_ball->IsActive())
		{
			_player->SetHp(_player->GetHp() - 20);
			_hpBar->SetValue(_player->GetHp() / 100.0f);
		}
		
		_ball->IsActive(false);
	}
}

void ArkaCollisionManager::BallCollisionBrick()
{
	for (auto blocks : _map->GetBricks())
	{
		for (auto block : blocks)
		{
			if (block->IsActive() == false)
				continue;

			if (block->GetCollider()->IsCollision(_ball->GetCollider()) == false)
				continue;

			block->BreakBrick();

			// 좌우 사이에 있었다.
			if (_ball->GetPos().x < block->GetCollider()->Right() && _ball->GetPos().x > block->GetCollider()->Left())
			{
				Vector curDir = _ball->GetDir();
				curDir.y *= -1.0f;

				_ball->SetDir(curDir);
			}

			// 위 아래 사이에 있었다.
			else
			{
				Vector curDir = _ball->GetDir();
				curDir.x *= -1.0f;

				_ball->SetDir(curDir);
			}
		}
	}
}

void ArkaCollisionManager::PlayerCollisionItem()
{
	if (_player->GetCollider()->IsCollision(_item->GetCollider()))
	{
		_item->IsActive(false);
	}
}

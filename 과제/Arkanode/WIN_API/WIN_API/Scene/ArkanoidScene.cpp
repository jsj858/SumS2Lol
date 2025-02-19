#include "framework.h"
#include "ArkanoidScene.h"

#include "Objects/Arkanoid/ArkaMap.h"
#include "Objects/Arkanoid/ArkaPlayer.h"
#include "Objects/Arkanoid/ArkaBall.h"
#include "Objects/Arkanoid/ArkaCollisionManager.h"
#include "Objects/Arkanoid/ArkaItem.h"
#include "Objects/Arkanoid/ArkanoidBlock.h"
#include "Objects/Arkanoid/ArkaHpBar.h"

ArkanoidScene::ArkanoidScene()
{
	_map = make_shared<ArkaMap>();
	_player = make_shared<ArkaPlayer>();
	_ball = make_shared<ArkaBall>(_player);
	_item = make_shared<ArkaItem>(_map->GetBricks()[0][0]);
	_map->GetBricks()[0][0]->SetItem(_item);

	_ui_hpBar = make_shared<ArkaHpBar>(CENTER + Vector(0, 300), Vector(600, 30));
	_ui_hpBar->SetValue(1.0);

	_collisionManager = make_shared<ArkaCollisionManager>(_player, _ball, _map, _item, _ui_hpBar);
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_map->Update();
	_player->Update();
	_ball->Update();
	_item->Update();
	_ui_hpBar->Update();
	_collisionManager->Update();
	
	Input();
}

void ArkanoidScene::Render(HDC hdc)
{
	_map->Render(hdc);
	_player->Render(hdc);
	_ball->Render(hdc);
	_item->Render(hdc);


	_ui_hpBar->Render(hdc);
}

void ArkanoidScene::Input()
{
	if (GetKeyState('A') & 0x8000)
	{
		_player->SetPos(_player->GetPos() += Vector(-1, 0) * 10);
	}

	if (GetKeyState('D') & 0x8000)
	{
		_player->SetPos(_player->GetPos() += Vector(1, 0) * 10);
	}

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (_ball->IsFire() == false)
		{
			_ball->IsFire(true);
			_ball->SetDir(Vector(0, -1));
		}
	}
}

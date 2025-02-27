#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circle = make_shared<CircleCollider>(Vector(450, 500), 100);
	_movingCircle = make_shared<CircleCollider>(Vector(0, 0), 60);
	
	_rect = make_shared<RectCollider>(Vector(800, 500), Vector(130, 50));
	_movingRect = make_shared<RectCollider>(Vector(0, 0), Vector(15, 70));

}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_movingCircle->SetCenter(mousePos);
	//_movingRect->SetCenter(mousePos);

	if (_circle->IsCollision(_movingRect))
	{
		_circle->SetRed();
	}
	else
	{
		_circle->SetGreen();
	}

	if (_rect->IsCollision(_movingCircle))
	{
		_rect->SetRed();
	}
	else
	{
		_rect->SetGreen();
	}

	_circle->Update();
	_movingCircle->Update();

	_rect->Update();
	_movingRect->Update();
}

void CollisionScene::Render(HDC hdc)
{
	_circle->Render(hdc);
	_movingCircle->Render(hdc);

	_rect->Render(hdc);
	_movingRect->Render(hdc);
}

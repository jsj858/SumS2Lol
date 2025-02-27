#include "framework.h"
#include "Program.h"

#include "Scene/PaintScene.h"
#include "Scene/CollisionScene.h"
#include "Scene/LineScene.h"
#include "Scene/LineCollisionScene.h"
#include "Scene/CannonScene.h"

Program::Program()
{
	//_scene = make_shared<PaintScene>();
	//_scene = make_shared<CollisionScene>();
	//_scene = make_shared<LineScen>();
	//_scene = make_shared<LineCollisionScene>();
	_scene = make_shared<CannonScene>();

	
}

Program::~Program()
{
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	_scene->Render(hdc);
}

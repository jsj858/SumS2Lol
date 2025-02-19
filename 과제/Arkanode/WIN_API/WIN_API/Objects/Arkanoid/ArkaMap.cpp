#include "framework.h"
#include "ArkaMap.h"

#include "Objects/Arkanoid/ArkanoidBlock.h"
#include "Objects/Arkanoid/ArkaPlayer.h"
#include "Objects/Arkanoid/ArkaBall.h"

ArkaMap::ArkaMap()
{
	_blocks.resize(_countY);

	Vector offset;
	int x = ((_brickSize.x + _brickGap.x) * _countX) / 2.0f;

	Vector temp = CENTER;
	offset.x = temp.x - x;
	offset.y = 200.0f;

	for (int y = 0; y < _countY; y++)
	{
		for (int x = 0; x < _countX; x++)
		{
			shared_ptr<ArkanoidBlock> brick = make_shared<ArkanoidBlock>(_brickSize);

			Vector brickPos;
			brickPos.x = (_brickSize.x + _brickGap.x) * x;
			brickPos.y = (_brickSize.y + _brickGap.y) * y;

			brick->SetPos(brickPos + offset);
			brick->IsActive(true);
			_blocks[y].push_back(brick);
		}
	}
}

ArkaMap::~ArkaMap()
{
}

void ArkaMap::Update()
{
	for (auto bricks : _blocks)
	{
		for (auto brick : bricks)
		{
			brick->Update();
		}
	}
	
}

void ArkaMap::Render(HDC hdc)
{
	for (auto bricks : _blocks)
	{
		for (auto brick : bricks)
		{
			brick->Render(hdc);
		}
	}
}

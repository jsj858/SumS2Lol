#include "framework.h"
#include "Cannon.h"

#include "Barrel.h"
#include "Ball.h"

Cannon::Cannon()
{
	
	_speed = 10.0f;

	_body = make_shared<CircleCollider>(CENTER, 50);
	
	_barrel = make_shared<Barrel>(_body);

	_poolCount = 30;
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Ball> ball = make_shared<Ball>();
		_balls.push_back(ball);
	}
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	_body->Update();
	_barrel->Update();

	for (auto ball : _balls)
	{
		ball->Update();

		if (ball->IsActive)
		{
			ball->AddForce(_ballSpeed);
		}
	}

	_delay += 0.1f;


	Fire();
	Move();
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->	 Render(hdc);

	for (auto ball : _balls)
	{
		ball->Render(hdc);
	}
}

void Cannon::Move()
{
	if (GetKeyState('A') & 0x8000)
	{
		_body->SetCenter(_body->GetCenter() + Vector(-1, 0) * _speed);
	}
	if (GetKeyState('D') & 0x8000)
	{
		_body->SetCenter(_body->GetCenter() + Vector(1, 0) * _speed);
	}
	if (GetKeyState('W') & 0x8000)
	{
		_barrel->SetAngle(_barrel->GetAngle() - 0.1f);
	}
	if (GetKeyState('S') & 0x8000)
	{
		_barrel->SetAngle(_barrel->GetAngle() + 0.1f);
	}

}

void Cannon::Fire()
{
	if (_delay < _attackSpeed)
		return;

	auto iter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<Ball> ball)
		{
			if (ball->IsActive == false)
				return true;
			return false;
		});

	if (iter == _balls.end())
		return;

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		(*iter)->SetPos(_barrel->GetMuzzle());
		(*iter)->SetDir(_barrel->GetDir());
		(*iter)->IsActive = true;

		// 중력
		//(*iter)->SetGravityAccel(0.1f);
		
		// sin 그래프
		(*iter)->SetAmplitude(30.0f);
		(*iter)->SetFrequency(0.02f);



		_delay = 0.0f;

		// 진자운동하기 위한 용도
	}
}

#pragma once

class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPos(Vector pos) { _circle->SetCenter(pos); }
	void AddForce(float v);
	void SetDir(Vector dir) { _direction = dir; }

	// 중력
	void SetGravityAccel(float gravityAccel) { _gravityAccel = gravityAccel; }

	// sin 그래프
	void SetAmplitude(float amplitude) { _amplitude = amplitude; }
	void SetFrequency(float frequency) { _frequency = frequency; }

	bool IsActive = false;

private:
	shared_ptr<CircleCollider> _circle;

	float _ballSpeed = 3;
	Vector _direction = Vector{ 1,0 };

	float _gravity = 9.8f;
	float _gravityAccel = 0.1f;

	float _amplitude = 0.0f;
	float _frequency = 0.0f;
};

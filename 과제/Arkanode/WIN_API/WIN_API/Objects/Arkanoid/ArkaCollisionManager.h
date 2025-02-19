#pragma once

class ArkaMap;
class ArkaPlayer;
class ArkaBall;
class ArkaItem;
class ArkaHpBar;

class ArkaCollisionManager
{
public:
	ArkaCollisionManager(shared_ptr<ArkaPlayer> player, shared_ptr<ArkaBall> ball, shared_ptr<ArkaMap> map, shared_ptr<ArkaItem> item, shared_ptr<ArkaHpBar> hpBar);
	~ArkaCollisionManager();

	void Update();

	void BallCollisionPlayer();
	void BallCollisionWall();
	void BallCollisionBrick();
	void PlayerCollisionItem();

private:
	shared_ptr<ArkaMap> _map;
	shared_ptr<ArkaPlayer> _player;
	shared_ptr<ArkaBall> _ball;
	shared_ptr<ArkaItem> _item;
	shared_ptr<ArkaHpBar> _hpBar;


};

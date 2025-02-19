#pragma once

class ArkaMap;
class ArkaPlayer;
class ArkaBall;
class ArkaInputManager;
class ArkaCollisionManager;
class ArkaItem;
class ArkaHpBar;

class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;

	void Input();

private:
	shared_ptr<ArkaMap> _map;
	shared_ptr<ArkaPlayer> _player;
	shared_ptr<ArkaBall> _ball;
	shared_ptr<ArkaItem> _item;
	shared_ptr<ArkaCollisionManager> _collisionManager;
	shared_ptr<ArkaHpBar> _ui_hpBar;
};

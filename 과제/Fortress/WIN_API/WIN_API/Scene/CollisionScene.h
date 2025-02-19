#pragma once

class CollisionScene : public Scene
{
public:
	CollisionScene();
	~CollisionScene();

	void Update() override;
	void Render(HDC hdc) override;

private:
	// shared_ptr<CircleCollider> _circle;
	// shared_ptr<CircleCollider> _movingCircle;

	// shared_ptr<RectCollider> _rect;
	// shared_ptr<RectCollider> _movingRect;

	shared_ptr<Collider> _circle;
	shared_ptr<Collider> _movingCircle;

	shared_ptr<Collider> _rect;
	shared_ptr<Collider> _movingRect;
	// rect ¿Í movingRect Ãß°¡
};

#pragma once


class LineScen : public Scene
{
public:
	LineScen();
	~LineScen();

	void Update() override;
	void Render(HDC hdc) override;
private:
	shared_ptr<Line> _floor;
	shared_ptr<Line> _line1;
	shared_ptr<Line> _shadow;
};

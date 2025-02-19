#pragma once

class ArkanoidBlock;
class ArkaPlayer;
class ArkaBall;


class ArkaMap
{
public:
	ArkaMap();
	~ArkaMap();

	void Update();
	void Render(HDC hdc);

	vector<vector<shared_ptr<ArkanoidBlock>>> GetBricks() { return _blocks; }
private:
	vector<vector<shared_ptr<ArkanoidBlock>>> _blocks;
	vector<shared_ptr<class AlkaItem>> _items;

	Vector _brickSize = Vector(100, 20);

	int _countX = 9;
	int _countY = 3;

	Vector _brickGap = Vector(2, 2);
};

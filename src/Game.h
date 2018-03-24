#pragma once

#include <vector>

#include "ConsoleApp.h"
#include "Field.h"
#include "Gold.h"
#include "Wall.h"
#include "WallFactory.h"
#include "Player.h"

using std::vector;

class Game : public ConsoleApp
{
public:
	Game();
	~Game();

	void run();
	void updateFrame();
	void pressKey(int keyCode);

	void drawObject(GameObject& gameObj);
	void eraseObject(GameObject& gameObj);
	void drawField(Field& field);

	bool isObstacle(int x, int y);

	vector<GameObject*> generateWalls(int nWalls);

private:
	const int UP_ARROW = 72;
	const int DOWN_ARROW = 80;
	const int LEFT_ARROW = 75;
	const int RIGHT_ARROW = 77;

	Field* field_;
	Gold* gold_;
	GameObject* wall_;
	vector<GameObject*> walls_;
	Player* player_;

	bool hasMultimapKeyValue(multimap<int, int> mMap, int key, int value);
};


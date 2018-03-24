#include <conio.h>
#include <algorithm>
#include <ctime>

#include "Game.h"

Game::Game()
{
	field_ = new Field();
	gold_ = new Gold();
	player_ = new Player();
}


Game::~Game()
{
	delete field_;
	delete gold_;
	delete player_;
}



void Game::run()
{
	srand(time(0));

	drawField(*field_);
	drawObject(*gold_);
	generateWalls(200);

	while (true) {
		if (_kbhit())
			pressKey(_getch());
		updateFrame();
		render();
		Sleep(50);
	}
}



void Game::updateFrame()
{
	drawObject(*player_);

	for (int i = 0; i < size(walls_); ++i)
		drawObject(*walls_[i]);
}



void Game::pressKey(int keyCode)
{
	eraseObject(*player_);

	if (keyCode == UP_ARROW) {
		player_->setDirection(GameObject::UP);
		if (isObstacle(player_->getPositionX(), player_->getPositionY() - 1) == false)
			player_->move();
	}
	else if (keyCode == DOWN_ARROW) {
		player_->setDirection(GameObject::DOWN);
		if (isObstacle(player_->getPositionX(), player_->getPositionY() + 1) == false)
			player_->move();
	}
	else if (keyCode == LEFT_ARROW) {
		player_->setDirection(GameObject::LEFT);
		if (isObstacle(player_->getPositionX() - 1, player_->getPositionY()) == false)
			player_->move();
	}
	else if (keyCode == RIGHT_ARROW) {
		player_->setDirection(GameObject::RIGHT);
		if (isObstacle(player_->getPositionX() + 1, player_->getPositionY()) == false)
			player_->move();
	}
}



void Game::drawObject(GameObject& gameObj)
{
	setChar(gameObj.getPositionX(), gameObj.getPositionY(), gameObj.getDisplayChar());
}



void Game::eraseObject(GameObject& gameObj)
{
	setChar(gameObj.getPositionX(), gameObj.getPositionY(), ' ');
}



void Game::drawField(Field& field)
{
	multimap<int, int> positionsXY = field.getPositionsXY();

	for (auto it = positionsXY.begin(); it != positionsXY.end(); ++it)
		setChar((*it).first, (*it).second, field.getDisplayChar());
}



bool Game::isObstacle(int x, int y)
{
	bool isObstacle = (getChar(x, y) == wall_->getDisplayChar()) ||
					  (getChar(x, y) == field_->getDisplayChar());

	if (isObstacle == true)
		return true;
	else
		return false;
}



vector<GameObject*> Game::generateWalls(int nWalls)
{
	int strength = 3;
	int x = 30;
	int y = 10;

	multimap<int, int> positionsXY;

	GameObjectFactory* wallFactory = new WallFactory();
	wall_ = wallFactory->createGameObject(30, 23);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(30, 23);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(32, 23);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(30, 22);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(31, 22);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(32, 22);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(28, 22);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(28, 21);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(28, 20);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(29, 20);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(30, 20);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(31, 20);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(32, 20);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(33, 20);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(34, 20);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(34, 21);
	walls_.push_back(wall_);
	wall_= wallFactory->createGameObject(34, 22);
	walls_.push_back(wall_);

	for (int i = 0; i < nWalls; ++i) {
		while (hasMultimapKeyValue(positionsXY, x, y) == true) {
			x = 18 + rand() % 28;
			y = 1 + rand() % 18;
		}
		positionsXY.insert(make_pair(x, y));
		wall_ = wallFactory->createGameObject(x, y);
		walls_.push_back(wall_);
	}

	delete wall_;
	delete wallFactory;

	return walls_;
}



bool Game::hasMultimapKeyValue(multimap<int, int> mMap, int key, int value)
{
	auto range = mMap.equal_range(key);
	auto pair = find_if(range.first, range.second,
		[&](auto& el) { return el.second == value; });

	if (pair != range.second)
		return true;
	else
		return false;
}

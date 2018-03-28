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
	delete wall_;
}



void Game::run()
{
	srand(time(0));

	drawField(*field_);
	drawObject(*gold_);

	generateWalls(200);
	for (int i = 0; i < size(walls_); ++i)
		drawObject(*walls_[i]);

	generateEnemies(10);
	for (int i = 0; i < size(enemies_); ++i)
		drawObject(*enemies_[i]);

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
					  (getChar(x, y) == field_->getDisplayChar()) ||
					  (getChar(x, y) == enemy_->getDisplayChar());

	if (isObstacle == true)
		return true;
	else
		return false;
}



vector<GameObject*> Game::generateWalls(int nWalls)
{
	// area for generating walls
	const int topLeftCornerX = 18;
	const int topLeftCornerY = 1;
	const int areaWidth = 28;
	const int areaHeight = 18;

	int randomX = 30;
	int randomY = 10;

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
		while (hasMultimapKeyValue(positionsXY, randomX, randomY) == true) {
			randomX = topLeftCornerX + rand() % areaWidth;
			randomY = topLeftCornerY + rand() % areaHeight;
		}
		positionsXY.insert(make_pair(randomX, randomY));
		wall_ = wallFactory->createGameObject(randomX, randomY);
		walls_.push_back(wall_);
	}

	delete wallFactory;

	return walls_;
}



vector<GameObject*> Game::generateEnemies(int nEnemies)
{
	// area for generating enemies
	const int topLeftCornerX = 18;
	const int topLeftCornerY = 1;
	const int areaWidth = 28;
	const int areaHeight = 15;
	const int distanceBetweenEnemies = 2;

	int randomX;
	int randomY;
	bool canGenerate = false;

	multimap<int, int> positionsXY;

	GameObjectFactory* enemyFactory = new EnemyFactory();

	for (int i = 0; i < nEnemies; ++i) {
		canGenerate = false;
		while (canGenerate == false) {
			randomX = topLeftCornerX + rand() % areaWidth;
			randomY = topLeftCornerY + rand() % areaHeight;

			canGenerate = (canGenerateEnemy(randomX, randomY)) &&
						  (!hasMultimapKeyValue(positionsXY, randomX, randomY));
		}

		for (int x = randomX - distanceBetweenEnemies; x <= randomX + distanceBetweenEnemies; ++x) {
			for (int y = randomY - distanceBetweenEnemies; y <= randomY + distanceBetweenEnemies; ++y) {
				if (hasMultimapKeyValue(positionsXY, x, y) == false)
					positionsXY.insert(make_pair(x, y));
			}
		}

		enemy_ = enemyFactory->createGameObject(randomX, randomY);
		enemies_.push_back(enemy_);
	}

	delete enemy_;
	delete enemyFactory;

	return enemies_;
}



bool Game::canGenerateEnemy(int x, int y)
{
	if (getChar(x, y) != ' ')
		return false;

	return true;
}



bool Game::hasMultimapKeyValue(multimap<int, int> mMap, int key, int value)
{
	auto range = mMap.equal_range(key);
	auto pair = find_if(range.first, range.second,
		[&value](auto& el) { return el.second == value; });

	if (pair != range.second)
		return true;
	else
		return false;
}

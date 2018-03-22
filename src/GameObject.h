#pragma once

class GameObject
{
public:
	enum Direction {
		UP = 1, DOWN, LEFT, RIGHT
	};

	GameObject();
	virtual ~GameObject() = 0;

	int getPositionX();
	int getPositionY();

	void setDisplayChar(char ch);
	char getDisplayChar();

protected:
	int positionX_;
	int positionY_;
	char displayChar_;
};


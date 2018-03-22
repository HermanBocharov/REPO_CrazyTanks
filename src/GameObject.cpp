#include "GameObject.h"

GameObject::GameObject() {}



GameObject::~GameObject() {}



int GameObject::getPositionX()
{
	return positionX_;
}



int GameObject::getPositionY()
{
	return positionY_;
}



void GameObject::setDisplayChar(char ch)
{
	displayChar_ = ch;
}



char GameObject::getDisplayChar()
{
	return displayChar_;
}
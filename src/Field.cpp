#include "Field.h"

Field::Field()
{
	positionX_ = 17;
	positionY_ = 0;
	height_ = 25;
	width_ = 30;
	displayChar_ = 219;
}



Field::~Field() {}



int Field::getHeight()
{
	return height_;
}



int Field::getWidth()
{
	return width_;
}



int Field::getPositionX()
{
	return positionX_;
}



int Field::getPositionY()
{
	return positionY_;
}



char Field::getDisplayChar()
{
	return displayChar_;
}



multimap<int, int> Field::getPositionsXY()
{
	multimap<int, int> positionsXY;

	for (int x = 0; x < width_; ++x)
		positionsXY.insert(make_pair(positionX_ + x, positionY_));

	for (int y = 1; y < height_ - 1; ++y)
		positionsXY.insert(make_pair(positionX_, positionY_ + y));

	for (int y = 1; y < height_ - 1; ++y)
		positionsXY.insert(make_pair(positionX_ + width_ - 1, positionY_ + y));

	for (int x = 0; x < width_; ++x)
		positionsXY.insert(make_pair(positionX_ + x, positionY_ + height_ - 1));

	return positionsXY;
}

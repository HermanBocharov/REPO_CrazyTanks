#ifndef FIELD_H
#define FIELD_H

#include <map>

using std::multimap;
using std::make_pair;

class Field
{
public:
	Field();
	~Field();

	int getHeight();
	int getWidth();

	int getPositionX();
	int getPositionY();
	multimap<int, int> getPositionsXY();

	char getDisplayChar();

private:
	int height_;
	int width_;
	int positionX_;
	int positionY_;
	char displayChar_;
};

#endif FIELD_H
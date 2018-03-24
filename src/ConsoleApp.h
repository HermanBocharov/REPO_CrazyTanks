#ifndef CONSOLEAPP_H
#define CONSOLEAPP_H

#include <Windows.h>

class ConsoleApp
{
public:
	ConsoleApp();
	virtual ~ConsoleApp();

	void setChar(int x, int y, char c);
	char getChar(int x, int y);

protected:
	void render();

private:
	static const int X_WINDOW_SIZE = 50;
	static const int Y_WINDOW_SIZE = 25;

	HANDLE writeHandle_;
	CHAR_INFO* consoleBuffer_;
	COORD bufferSize_;
	COORD charPosition_;
	SMALL_RECT writeArea_;
};

#endif CONSOLEAPP_H
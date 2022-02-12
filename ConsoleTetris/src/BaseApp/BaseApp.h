#pragma once

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

using namespace std;

class BaseApp
{
private:
	HANDLE mConsole;
	HANDLE mConsoleIn;

	CHAR_INFO* mChiBuffer;
	COORD mDwBufferSize;
	COORD mDwBufferCoord;
	SMALL_RECT mLpWriteRegion;

	void Render();

public:

	int X_SIZE;
	int Y_SIZE;
	bool GameOver;

	BaseApp();
	virtual ~BaseApp();

	void Run();

	void SetChar(int x, int y, wchar_t c);
	wchar_t GetChar(int x, int y);

	
	virtual void UpdateF(float deltaTime) {}

	virtual void KeyPressed(int btnCode) {}
};
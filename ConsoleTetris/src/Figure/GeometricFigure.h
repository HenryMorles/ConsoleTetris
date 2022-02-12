#pragma once

struct Point {
	int X;
	int Y;
	void SetCord(int x, int y);
};

class GeometricFigure
{
public:
	Point Points[4];            //Shape points. Point 0 is central, the position of the remaining points will curl from it
	int RotationPosition;  //Turn position number
 
	virtual void ResetPosition() = 0;   //Update points relative to point 0
};


#include "Square.h"


Square::Square()
{
	RotationPosition = 0;
}

void Square::ResetPosition()
{
	Points[1].X = Points[0].X + 1;
	Points[1].Y = Points[0].Y;

	Points[2].X = Points[0].X;
	Points[2].Y = Points[0].Y + 1;

	Points[3].X = Points[0].X + 1;
	Points[3].Y = Points[0].Y + 1;
}
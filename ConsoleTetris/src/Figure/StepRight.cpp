#include "StepRight.h"

StepRight::StepRight()
{
	RotationPosition = 0;
}

void StepRight::ResetPosition()
{
	if (RotationPosition == 0 || RotationPosition == 2)
	{
		Points[1].X = Points[0].X;
		Points[1].Y = Points[0].Y + 1;

		Points[2].X = Points[0].X - 1;
		Points[2].Y = Points[0].Y + 1;

		Points[3].X = Points[0].X + 1;
		Points[3].Y = Points[0].Y;
	}
	else if (RotationPosition == 1 || RotationPosition == 3)
	{
		Points[1].X = Points[0].X + 1;
		Points[1].Y = Points[0].Y;

		Points[2].X = Points[0].X + 1;
		Points[2].Y = Points[0].Y + 1;

		Points[3].X = Points[0].X;
		Points[3].Y = Points[0].Y - 1;
	}
}

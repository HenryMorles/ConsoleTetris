#include "Triangle.h"

Triangle::Triangle()
{
	RotationPosition = 0;
}

void Triangle::ResetPosition()
{
	switch (RotationPosition)
	{
	case 0:
		Points[1].X = Points[0].X + 1;
		Points[1].Y = Points[0].Y;

		Points[2].X = Points[0].X;
		Points[2].Y = Points[0].Y - 1;

		Points[3].X = Points[0].X - 1;
		Points[3].Y = Points[0].Y;
		break;

	case 1:
		Points[1].X = Points[0].X;
		Points[1].Y = Points[0].Y + 1;

		Points[2].X = Points[0].X + 1;
		Points[2].Y = Points[0].Y;

		Points[3].X = Points[0].X;
		Points[3].Y = Points[0].Y - 1;
		break;

	case 2:
		Points[1].X = Points[0].X - 1;
		Points[1].Y = Points[0].Y;

		Points[2].X = Points[0].X;
		Points[2].Y = Points[0].Y + 1;

		Points[3].X = Points[0].X + 1;
		Points[3].Y = Points[0].Y;
		break;

	case 3:
		Points[1].X = Points[0].X;
		Points[1].Y = Points[0].Y - 1;

		Points[2].X = Points[0].X - 1;
		Points[2].Y = Points[0].Y;

		Points[3].X = Points[0].X;
		Points[3].Y = Points[0].Y + 1;
		break;
	}
}

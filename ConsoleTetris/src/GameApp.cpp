#include "GameApp.h"

GameApp::GameApp() : FigurePosition_X(8), FigurePosition_Y(2), FieldWidth(25), FieldHeight(22), PreviewZone(16), PreviewPoint_X(20), PreviewPoint_Y(4) {
	StartGame = true;
	Acceleration = false;
	NextFigere = rand() % 6;
	Figure = &square;
}

void GameApp::BuildingBorders()
{
	for (int i = 0; i < FieldWidth; ++i)
	{

		for (int j = 0; j < FieldHeight; ++j)
		{
			if (!i || i == FieldWidth - 1 || i == PreviewZone || !j || j == FieldHeight - 1)
			{
				SetChar(i, j, L'#', 82, 0, 0);
			}
			else if (i < PreviewZone && j < FieldHeight - 1)
			{
				SetChar(i, j, L'.', 0, 0, 0);
			}
		}
	}
}

void GameApp::FigureMovement()
{
	if (GetChar(FigurePosition_X, FigurePosition_Y + 1) == L'&') //If the figures are too high - the game is over
	{
		GameOver = true;
	}

	if (GetChar(Figure->Points[0].X, Figure->Points[0].Y + 1) != L'#' &&
		GetChar(Figure->Points[1].X, Figure->Points[1].Y + 1) != L'#' &&
		GetChar(Figure->Points[2].X, Figure->Points[2].Y + 1) != L'#' &&
		GetChar(Figure->Points[3].X, Figure->Points[3].Y + 1) != L'#' &&
		GetChar(Figure->Points[0].X, Figure->Points[0].Y + 1) != L'&' &&
		GetChar(Figure->Points[1].X, Figure->Points[1].Y + 1) != L'&' &&
		GetChar(Figure->Points[2].X, Figure->Points[2].Y + 1) != L'&' &&
		GetChar(Figure->Points[3].X, Figure->Points[3].Y + 1) != L'&') //If encountered with '#' or '&' movement is not possible
	{
		if (Acceleration)
		{
			Figure->Points[0].SetCord(Figure->Points[0].X, ++Figure->Points[0].Y);
			Figure->ResetPosition();
			Watch.Start();
			for (int i = 0; i < 4; ++i) {
				SetChar(Figure->Points[i].X, Figure->Points[i].Y - 1, L'.');
			}
		}
		else if (Watch.Now() >= 350)
		{
			Figure->Points[0].SetCord(Figure->Points[0].X, ++Figure->Points[0].Y); //Set the coordinates of the center point of the shape
			Figure->ResetPosition(); //Update other points
			Watch.Start();
			for (int i = 0; i < 4; ++i) {
				SetChar(Figure->Points[i].X, Figure->Points[i].Y - 1, L'.');
			}
		}
	}
	else if (GetChar(Figure->Points[0].X, Figure->Points[0].Y + 1) == L'#' ||
		GetChar(Figure->Points[1].X, Figure->Points[1].Y + 1) == L'#' ||
		GetChar(Figure->Points[2].X, Figure->Points[2].Y + 1) == L'#' ||
		GetChar(Figure->Points[3].X, Figure->Points[3].Y + 1) == L'#' ||
		GetChar(Figure->Points[0].X, Figure->Points[0].Y + 1) == L'&' ||
		GetChar(Figure->Points[1].X, Figure->Points[1].Y + 1) == L'&' ||
		GetChar(Figure->Points[2].X, Figure->Points[2].Y + 1) == L'&' ||
		GetChar(Figure->Points[3].X, Figure->Points[3].Y + 1) == L'&') //Update other points
	{
		for (int i = 0; i < 4; ++i) {
			SetChar(Figure->Points[i].X, Figure->Points[i].Y, L'&', 0, 0, 180);
		}
		RandomFigure();
		Figure->Points[0].SetCord(FigurePosition_X, FigurePosition_Y);
		Figure->RotationPosition = 0;
		Figure->ResetPosition();
		Acceleration = false;
	}
	for (int i = 0; i < 4; ++i)
	{
		SetChar(Figure->Points[i].X, Figure->Points[i].Y, L'*', 120, 0, 0);
	}
}

void GameApp::KeyPressed(int btnCode)
{
	if (btnCode == 75 && !Acceleration) //LEFT
	{
		if ((GetChar(Figure->Points[0].X - 1, Figure->Points[0].Y) != L'#') &&
			(GetChar(Figure->Points[1].X - 1, Figure->Points[1].Y) != L'#') &&
			(GetChar(Figure->Points[2].X - 1, Figure->Points[2].Y) != L'#') &&
			(GetChar(Figure->Points[3].X - 1, Figure->Points[3].Y) != L'#') &&
			(GetChar(Figure->Points[0].X - 1, Figure->Points[0].Y) != L'&') &&
			(GetChar(Figure->Points[1].X - 1, Figure->Points[1].Y) != L'&') &&
			(GetChar(Figure->Points[2].X - 1, Figure->Points[2].Y) != L'&') &&
			(GetChar(Figure->Points[3].X - 1, Figure->Points[3].Y) != L'&')) //Checking the ability to move to the left
		{
			Figure->Points[0].X--;
			Figure->ResetPosition();
			for (int i = 0; i < 4; ++i) {
				SetChar(Figure->Points[i].X + 1, Figure->Points[i].Y, L'.');
			}
		}
	}

	else if (btnCode == 77 && !Acceleration) //RIGHT
	{
		if ((GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y) != L'#') &&
			(GetChar(Figure->Points[1].X + 1, Figure->Points[1].Y) != L'#') &&
			(GetChar(Figure->Points[2].X + 1, Figure->Points[2].Y) != L'#') &&
			(GetChar(Figure->Points[3].X + 1, Figure->Points[3].Y) != L'#') &&
			(GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y) != L'&') &&
			(GetChar(Figure->Points[1].X + 1, Figure->Points[1].Y) != L'&') &&
			(GetChar(Figure->Points[2].X + 1, Figure->Points[2].Y) != L'&') &&
			(GetChar(Figure->Points[3].X + 1, Figure->Points[3].Y) != L'&')) //Checking the possibility of movement to the right
		{
			{
				Figure->Points[0].X++;
				Figure->ResetPosition();
				for (int i = 0; i < 4; ++i) {
					SetChar(Figure->Points[i].X - 1, Figure->Points[i].Y, L'.');
				}
			}
		}
	}

	else if (btnCode == 80)   //Down
	{
		Acceleration = true;
	}

	else if (btnCode == 32 && !Acceleration) // Space
	{
		bool CanRotation = false;
		if (Figure == &straight)
		{
			if (Figure->RotationPosition == 0 || Figure->RotationPosition == 2)
			{
				if (GetChar(Figure->Points[0].X + 2, Figure->Points[0].Y) == L'.' &&
					GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y) == L'.' &&
					GetChar(Figure->Points[0].X - 1, Figure->Points[0].Y) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y + 3) == L'.') //Checking the possibility of rotation
				{
					++Figure->RotationPosition;
					CanRotation = true;
				}
			}
			else if (Figure->RotationPosition == 1 || Figure->RotationPosition == 3)
			{
				if (GetChar(Figure->Points[0].X, Figure->Points[0].Y - 1) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y + 1) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y + 2) == L'.')//Checking the possibility of rotation
				{
					Figure->RotationPosition < 3 ? ++Figure->RotationPosition : Figure->RotationPosition = 0;
					CanRotation = true;
				}
			}
		}
		else if (Figure == &triangle)
		{
			switch (Figure->RotationPosition)
			{
			case 0:
				if (GetChar(Figure->Points[0].X, Figure->Points[0].Y + 1) == L'.')//Checking the possibility of rotation
				{
					++Figure->RotationPosition;
					CanRotation = true;
				}
				break;

			case 1:
				if (GetChar(Figure->Points[0].X, Figure->Points[0].Y + 2) == L'.' &&
					GetChar(Figure->Points[0].X - 1, Figure->Points[0].Y) == L'.')//Checking the possibility of rotation
				{
					++Figure->RotationPosition;
					CanRotation = true;
				}
				break;

			case 2:
				if (GetChar(Figure->Points[0].X, Figure->Points[0].Y + 2) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y - 1) == L'.')//Checking the possibility of rotation
				{
					++Figure->RotationPosition;
					CanRotation = true;
				}
				break;

			case 3:
				if (GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y + 2) == L'.')//Checking the possibility of rotation
				{
					Figure->RotationPosition = 0;
					CanRotation = true;
				}
				break;
			}
		}
		if (Figure == &stepLeft)
		{
			if (Figure->RotationPosition == 0 || Figure->RotationPosition == 2)
			{
				if (GetChar(Figure->Points[0].X, Figure->Points[0].Y + 2) == L'.' &&
					GetChar(Figure->Points[0].X - 1, Figure->Points[0].Y + 1) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y - 1) == L'.')//Checking the possibility of rotation
				{
					++Figure->RotationPosition;
					CanRotation = true;
				}
			}
			else if (Figure->RotationPosition == 1 || Figure->RotationPosition == 3)
			{
				if (GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y + 1) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y + 1) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y + 2) == L'.')//Checking the possibility of rotation
				{
					Figure->RotationPosition < 3 ? ++Figure->RotationPosition : Figure->RotationPosition = 0;
					CanRotation = true;
				}
			}
		}
		if (Figure == &stepRight)
		{
			if (Figure->RotationPosition == 0 || Figure->RotationPosition == 2)
			{
				if (GetChar(Figure->Points[0].X, Figure->Points[0].Y + 2) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y - 1) == L'.' &&
					GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y + 1) == L'.')//Checking the possibility of rotation
				{
					++Figure->RotationPosition;
					CanRotation = true;
				}
			}
			else if (Figure->RotationPosition == 1 || Figure->RotationPosition == 3)
			{
				if (GetChar(Figure->Points[0].X - 1, Figure->Points[0].Y + 1) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y + 1) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y + 2) == L'.')//Checking the possibility of rotation
				{
					Figure->RotationPosition < 3 ? ++Figure->RotationPosition : Figure->RotationPosition = 0;
					CanRotation = true;
				}
			}
		}
		else if (Figure == &injection)
		{

			switch (Figure->RotationPosition)
			{
			case 0:
				if (GetChar(Figure->Points[0].X, Figure->Points[0].Y + 2) == L'.' &&
					GetChar(Figure->Points[0].X - 1, Figure->Points[0].Y - 1) == L'.' &&
					GetChar(Figure->Points[0].X - 1, Figure->Points[0].Y) == L'.' &&
					GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y) == L'.')//Checking the possibility of rotation
				{
					++Figure->RotationPosition;
					CanRotation = true;
				}
				break;

			case 1:
				if (GetChar(Figure->Points[0].X, Figure->Points[0].Y + 1) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y - 1) == L'.' &&
					GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y - 1) == L'.')//Checking the possibility of rotation
				{
					++Figure->RotationPosition;
					CanRotation = true;

				}
				break;

			case 2:
				if (GetChar(Figure->Points[0].X, Figure->Points[0].Y + 2) == L'.' &&
					GetChar(Figure->Points[0].X - 1, Figure->Points[0].Y) == L'.' &&
					GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y) == L'.' &&
					GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y + 1) == L'.')//Checking the possibility of rotation
				{
					++Figure->RotationPosition;
					CanRotation = true;
				}
				break;

			case 3:
				if (GetChar(Figure->Points[0].X + 1, Figure->Points[0].Y + 2) == L'.' &&
					GetChar(Figure->Points[0].X - 1, Figure->Points[0].Y + 1) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y + 1) == L'.' &&
					GetChar(Figure->Points[0].X, Figure->Points[0].Y - 1) == L'.')//Checking the possibility of rotation
				{
					Figure->RotationPosition = 0;
					CanRotation = true;
				}
				break;
			}

		}
		if (CanRotation)
		{
			for (int i = 0; i < 4; ++i) {
				SetChar(Figure->Points[i].X, Figure->Points[i].Y, L'.');
			}
			Figure->ResetPosition();
		}
	}
}

void GameApp::UpdateF(float deltaTime)
{
	if (StartGame) //Called only once per game
	{
		RandomFigure();
		BuildingBorders();
		Watch.Start();
		Figure->Points[0].SetCord(FigurePosition_X, FigurePosition_Y);
		Figure->ResetPosition();
		StartGame = false;

	}
	else
	{
		FigureMovement();
		FindingFilledLine();
	}
}

void GameApp::RandomFigure()
{
	switch (NextFigere)
	{
	case 0:
		Figure = &square;
		break;

	case 1:
		Figure = &straight;
		break;

	case 2:
		Figure = &triangle;
		break;

	case 3:
		Figure = &stepLeft;
		break;

	case 4:
		Figure = &stepRight;
		break;

	case 5:
		Figure = &injection;
		break;
	}
	NextFigere = rand() % 6;
	PreviewFigure();
}

void GameApp::FindingFilledLine()
{
	for (int i = 1; i < FieldHeight - 1; ++i)
	{
		bool isFilledRow = true;
		for (int j = 1; j < PreviewZone; ++j) //Search for a filled line
		{
			if (GetChar(j, i) != '&')
			{
				isFilledRow = false;
				break;
			}
		}
		if (isFilledRow) //Deleting and moving other lines
		{
			for (int j = i; j > 1; --j)
			{
				for (int k = 1; k < PreviewZone; ++k)
				{
					if (GetChar(k, j - 1) == L'&')
					{
						SetChar(k, j, GetChar(k, j - 1), 0, 0, 180);
					}
					else
					{
						SetChar(k, j, GetChar(k, j - 1));
					}
				}
			}
		}
	}
}

void GameApp::PreviewFigure()
{
	for (int i = PreviewPoint_Y - 1; i < PreviewPoint_Y + 3; ++i) //Sketching the previous figure preview
	{
		for (int j = PreviewPoint_X - 1; j < PreviewPoint_X + 2; ++j)
		{
			SetChar(j, i, L' ');
		}
	}
	SetChar(PreviewPoint_X, PreviewPoint_Y, L'*', 40, 0, 0);
	switch (NextFigere)
	{
	case 0:
		SetChar(PreviewPoint_X + 1, PreviewPoint_Y, L'*', 40, 0, 0);    // **
		SetChar(PreviewPoint_X, PreviewPoint_Y + 1, L'*', 40, 0, 0);    // **
		SetChar(PreviewPoint_X + 1, PreviewPoint_Y + 1, L'*', 40, 0, 0);
		break;

	case 1:
		SetChar(PreviewPoint_X, PreviewPoint_Y - 1, L'*', 40, 0, 0);   // *
		SetChar(PreviewPoint_X, PreviewPoint_Y + 1, L'*', 40, 0, 0);   // *
		SetChar(PreviewPoint_X, PreviewPoint_Y + 2, L'*', 40, 0, 0);   // *
		break;                                               // * 

	case 2:
		SetChar(PreviewPoint_X, PreviewPoint_Y - 1, L'*', 40, 0, 0);  //  *
		SetChar(PreviewPoint_X + 1, PreviewPoint_Y, L'*', 40, 0, 0);  // ***
		SetChar(PreviewPoint_X - 1, PreviewPoint_Y, L'*', 40, 0, 0);
		break;

	case 3:
		SetChar(PreviewPoint_X - 1, PreviewPoint_Y, L'*', 40, 0, 0);   //  **
		SetChar(PreviewPoint_X, PreviewPoint_Y + 1, L'*', 40, 0, 0);   //   **
		SetChar(PreviewPoint_X + 1, PreviewPoint_Y + 1, L'*', 40, 0, 0);
		break;

	case 4:
		SetChar(PreviewPoint_X, PreviewPoint_Y + 1, L'*', 40, 0, 0);   //    **
		SetChar(PreviewPoint_X + 1, PreviewPoint_Y, L'*', 40, 0, 0);   //   **
		SetChar(PreviewPoint_X - 1, PreviewPoint_Y + 1, L'*', 40, 0, 0);
		break;

	case 5:
		SetChar(PreviewPoint_X, PreviewPoint_Y - 1, L'*', 40, 0, 0);     //   *   
		SetChar(PreviewPoint_X, PreviewPoint_Y + 1, L'*', 40, 0, 0);     //   *  
		SetChar(PreviewPoint_X - 1, PreviewPoint_Y + 1, L'*', 40, 0, 0); //  **  
		break;
	}
}

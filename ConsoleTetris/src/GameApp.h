#pragma once

#include "BaseApp/BaseApp.h"
#include "BaseApp/PerformanceCounter.h"
#include "Figure/Square.h"
#include "Figure/Straight.h"
#include "Figure/Triangle.h"
#include "Figure/StepLeft.h"
#include "Figure/StepRight.h"
#include "Figure/Injection.h"


class GameApp : public BaseApp
{
public:
	
	GameApp();

private:

	Square square; //Objects of geometric shapes
	Straight straight;
	Triangle triangle;
	StepLeft stepLeft;
	StepRight stepRight;
	Injection injection;
	GeometricFigure* Figure;

	CStopwatch Watch;

	const int FieldWidth;
	const int FieldHeight;
	const int PreviewZone;

    //The starting coordinates of the shape
	const int FigurePosition_X; 
	const int FigurePosition_Y;

	//The point at which the figure preview will appear
	const int PreviewPoint_X;
	const int PreviewPoint_Y;

	int NextFigere; //Number of the next figure to draw a preview
	bool StartGame; 
	bool Acceleration; 

	void BuildingBorders(); //Builds a frame
	void FigureMovement(); 
	void RandomFigure(); //Generates and places a random shape into a variable "Figure"
	void FindingFilledLine();//Looks for a filled line, and removes it
	void PreviewFigure(); //Draws a preview of the next shape

	virtual void KeyPressed(int btnCode)override;
	virtual void UpdateF(float deltaTime)override;
};


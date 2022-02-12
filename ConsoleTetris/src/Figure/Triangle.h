#pragma once

#include "GeometricFigure.h"

class Triangle : public GeometricFigure                 //   *
{                                                       //  ***
public:
	Triangle();

	virtual void ResetPosition()override;
};


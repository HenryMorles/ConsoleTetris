#pragma once

#include "GeometricFigure.h"

class Straight : public GeometricFigure                // ****
{
public:
	Straight();

	virtual void ResetPosition()override;
};


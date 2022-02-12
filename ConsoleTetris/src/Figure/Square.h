#pragma once

#include "GeometricFigure.h"

class Square : public GeometricFigure                  // **
{                                                      // **  
public:
	Square();

	virtual void ResetPosition()override;
};


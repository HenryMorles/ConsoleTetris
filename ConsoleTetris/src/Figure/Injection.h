#pragma once

#include "GeometricFigure.h"

class Injection : public GeometricFigure                   //   * 
{														   //   * 
public:													   //  ** 
	Injection();

	virtual void ResetPosition()override;
};


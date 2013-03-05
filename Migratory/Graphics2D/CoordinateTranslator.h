#pragma once
#include "Point.h"
#include "Point2D.h"

using namespace std;

class CoordinateTranslator
{
private:
	unsigned _screenWidth;
	unsigned _screenHeight;
	
	float _worldWidth;
	float _worldHeight;

	Point2D _lowerLeft;

public:
	CoordinateTranslator(void);
	CoordinateTranslator( unsigned, unsigned, float, float, Point2D );
	~CoordinateTranslator(void);

	Point2D screenToWorld( Point& const );
	void translatePointToWorld( Point2D& );
	
	Point worldToScreen( Point2D& );

	unsigned worldToScreenDistanceY( float );
	unsigned worldToScreenDistanceX( float );
};


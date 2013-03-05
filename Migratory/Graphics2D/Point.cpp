#include "Point.h"



Point::Point(void)
{
}

Point::Point( int x, int y )
{
	this->_x = x;
	this->_y = y;
}

Point::~Point(void)
{
}

int Point::getX( void ) 
{
	return this->_x;
}

int Point::getY( void ) 
{
	return this->_y;
}
	
void Point::setX( int x )
{
	this->_x = x;
}

void Point::setY( int y )
{
	this->_y = y;
}
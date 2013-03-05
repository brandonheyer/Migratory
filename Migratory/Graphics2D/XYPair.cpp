#include "XYPair.h"
#include <math.h>

const float XYPair::TOL = 0.000001f;

XYPair::XYPair(void)
{
	this->set( 0, 0 );
}

XYPair::XYPair( float x, float y)
{
	this->set( x, y );
}

XYPair::~XYPair(void)
{
}

XYPair XYPair::operator = ( XYPair p )
{
	return XYPair( p.getX(), p.getY() );
}

bool XYPair::operator == ( const XYPair& p )
{
	float dx = fabs( this->_x - p.getX() );
	float dy = fabs( this->_y - p.getY() );
	
	return dx < TOL && dy < TOL;
}

float XYPair::getX( void ) const
{
	return this->_x;
}

float XYPair::getY( void ) const
{
	return this->_y;
}

void XYPair::set( float x, float y )
{
	this->_x = x;
	this->_y = y;
}

void XYPair::setX( float x )
{
	this->_x = x;
}

void XYPair::setY( float y )
{
	this->_y = y;
}

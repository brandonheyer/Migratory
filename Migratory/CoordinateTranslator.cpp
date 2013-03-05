#include "Graphics2D\CoordinateTranslator.h"


CoordinateTranslator::CoordinateTranslator(void)
{
}

CoordinateTranslator::CoordinateTranslator( 
	unsigned screenWidth, 
	unsigned screenHeight, 
	float worldWidth, 
	float worldHeight, 
	Point2D lowerLeft )
{
	this->_screenWidth = screenWidth;
	this->_screenHeight = screenHeight;
	this->_worldWidth = worldWidth;
	this->_worldHeight = worldHeight;
	this->_lowerLeft = lowerLeft;
}

CoordinateTranslator::~CoordinateTranslator(void)
{
}

Point2D CoordinateTranslator::screenToWorld( Point& p ) 
{
	float worldX = ( ( this->_worldWidth * p.getX() ) / this->_screenWidth ) + _lowerLeft.getX();
	float worldY = this->_worldHeight + this->_lowerLeft.getY() - 
		( ( p.getY() * this->_worldHeight ) / this->_screenHeight );

	return Point2D( worldX, worldY );
}

void CoordinateTranslator::translatePointToWorld( Point2D& p )
{
	float worldX = ( ( this->_worldWidth * p.getX() ) / this->_screenWidth ) + _lowerLeft.getX();
	float worldY = this->_worldHeight + this->_lowerLeft.getY() - 
		( ( p.getY() * this->_worldHeight ) / this->_screenHeight );
	
	p.setX( worldX );
	p.setY( worldY );
}
	
Point CoordinateTranslator::worldToScreen( Point2D& p )
{
	unsigned screenX = ( this->_screenWidth / this->_worldWidth ) * ( p.getX() - this->_lowerLeft.getX() );
	unsigned screenY = this->_screenHeight - ( this->_screenHeight / this->_worldHeight ) *
			( p.getY() - this->_lowerLeft.getY() );

	return Point( screenX, screenY );
}

unsigned CoordinateTranslator::worldToScreenDistanceY( float d )
{
	return ( this->_screenHeight * d ) / this->_worldHeight;
}

unsigned CoordinateTranslator::worldToScreenDistanceX( float d ) 
{
	return ( this->_screenWidth * d ) / this->_worldWidth;
}
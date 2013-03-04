#include "Point2D.h"

static const Point2D ZERO_POINT = Point2D();

Point2D::Point2D( void ) { }

Point2D::Point2D( float x, float y ) : XYPair( x, y ) { }

Point2D::~Point2D(void) { }

Vector2D Point2D::operator - ( const Point2D& rhs ) const
{
	return Vector2D( _x - rhs.getX(), this->_y - rhs.getY() );
}

Point2D Point2D::operator + ( const Vector2D& rhs ) const 
{
	return Point2D( this->_x + rhs.getX(), this->_y + rhs.getY() );
}

Point2D& Point2D::operator += ( const Vector2D& rhs )
{
	this->_x += rhs.getX();
	this->_y += rhs.getY();

	return *this;
}

Point2D Point2D::scalePlus( const float scalar, const Vector2D& v ) const
{
	return Point2D( this->_x + ( v.getX() * scalar ), this->_y + ( v.getY() * scalar ) );
}

void Point2D::scalePlusEquals( const float scalar, const Vector2D& v )
{
		this->_x += v.getX() * scalar;
		this->_y += v.getY() * scalar;
}
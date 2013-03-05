#include "Vector2D.h"
#include <math.h>

const Vector2D Vector2D::ZERO_VEC = Vector2D();

Vector2D::Vector2D( void ) {}

Vector2D::Vector2D( float x, float y) : XYPair( x, y ) {}

Vector2D::Vector2D( XYPair p1, XYPair p2 )
{
	this->_x = p1.getX() - p2.getX();
	this->_y = p1.getY() - p2.getY();
}

Vector2D::~Vector2D(void) { }

float Vector2D::angle( void )
{
	if ( this->magnitudeSq() < TOL * TOL &&
		 this->magnitudeSq() > TOL * TOL * -1 ) {
			 return 0.0f;
	}

	return atan2( this->_y, this->_x );
}

float Vector2D::magnitude( void )
{
	return sqrtf( this->magnitudeSq() );
}

float Vector2D::magnitudeSq( void )
{
	return ( this->_x * this->_x ) + ( this->_y * this->_y );
}
	
void Vector2D::negate( void )
{
	this->_x *= -1;
	this->_y *= -1;	
}

void Vector2D::normalize( void )
{
	if ( this->magnitudeSq() < TOL * TOL &&
		 this->magnitudeSq() > TOL * TOL * -1 ) {
			 return;
	}

	if ( *this == ZERO_VEC ) {
		return;
	}

	float mag = this->magnitude();
	float xMag = this->_x / mag;
	float yMag = this->_y / mag;

	this->_x = xMag;
	this->_y = yMag;
}

void Vector2D::reflectX( void )
{
	this->_x *= -1;
}

void Vector2D::reflectY( void )
{
	this->_y *= -1;
}

void Vector2D::truncate( float d )
{
	if ( this->magnitudeSq() > d * d ) {
		this->normalize();
		*this *= d;
	}
}

void Vector2D::rotate( float angle )
{
	float ca = cos( angle );
	float sa = sin( angle );

	float xt = ( this->_x * ca ) - ( this->_y * sa );
	float yt = ( this->_y * ca ) - ( this->_x * sa );

	this->_x = xt;
	this->_y = yt;
}

Vector2D Vector2D::getLeftOrtho( void )
{
	return Vector2D( -1 * this->_y, this->_x );
}

Vector2D Vector2D::getRightOrtho( void )
{
	return Vector2D( this->_y, -1 * this->_x );
}

Vector2D Vector2D::getNormalized( void )
{
	if ( this->magnitudeSq() < TOL * TOL &&
		 this->magnitudeSq() > TOL * TOL * -1 ) {
			 return *this;
	}

	if ( *this == ZERO_VEC ) {
		return *this;
	}

	return Vector2D( this->_x / this->magnitude(), this->_y / this->magnitude() );
}

void Vector2D::setLeftOrtho( void )
{
	float temp = this->_x;
	this->_x = -1 * this->_y;
	this->_y = temp;
}

void Vector2D::setRightOrtho( void )
{
	float temp = this->_x;
	this->_x = this->_y;
	this->_y = -1 * temp;
}
	
float Vector2D::dot( Vector2D rhs )
{
	return this->_x * rhs.getX() + this->_y * rhs.getY();
}

Vector2D& Vector2D::operator = ( const Vector2D& rhs ) 
{
	if ( this != &rhs ) {
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}

	return * this;
}

Vector2D Vector2D::operator - ( const Vector2D& rhs ) const
{
	return Vector2D( this->_x - rhs.getX(), this->_y - rhs.getY() );
}

Vector2D& Vector2D::operator -= ( const Vector2D& rhs )
{
	this->_x -= rhs.getX();
	this->_y -= rhs.getY();

	return *this;
}

Vector2D Vector2D::operator + ( const Vector2D& rhs ) const
{
	return Vector2D( this->_x + rhs.getX(), this->_y + rhs.getY() );
}

Vector2D& Vector2D::operator += ( const Vector2D& rhs )
{
	this->_x += rhs.getX();
	this->_y += rhs.getY();

	return *this;
}

Vector2D Vector2D::operator * ( const float rhs ) const
{
	return Vector2D( this->_x * rhs, this->_y * rhs );
}

Vector2D& Vector2D::operator *= ( float rhs )
{
	this->_x *= rhs;
	this->_y *= rhs;

	return *this;
}

Vector2D Vector2D::operator /  ( const float rhs ) const
{
	if ( rhs == 0 ) {
		throw "Cannot divide Vector2D by 0";
	}

	return Vector2D( this->_x / rhs, this->_y / rhs );
}

Vector2D& Vector2D::operator /= ( float rhs )
{
	if ( rhs == 0 ) {
		throw "Cannot divide Vector2D by 0";
	}

	this->_x /= rhs;
	this->_y /= rhs;

	return *this;
}

Vector2D Vector2D::scalePlus( const float scalar, const Vector2D& v ) const
{
	return Vector2D( this->_x + ( v.getX() * scalar ), this->_y + ( v.getY() * scalar ) );
}

void Vector2D::scalePlusEquals( const float scalar, const Vector2D& v )
{
	this->_x += v.getX() * scalar;
	this->_y += v.getY() * scalar;
}

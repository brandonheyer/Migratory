#include "Vector2D.h"


Vector2D::Vector2D( void )
{
}

Vector2D::Vector2D( float x, float y) : XYPair( x, y ) {}

Vector2D::Vector2D( XYPair p1, XYPair p2 )
{
}

Vector2D::~Vector2D(void)
{
}

float Vector2D::angle( void )
{
}

float Vector2D::magnitude( void )
{
}

float Vector2D::magnitudeSq( void )
{
}
	
void Vector2D::negate( void )
{
}

void Vector2D::normalize( void )
{
}

void Vector2D::reflectX( void )
{
}

void Vector2D::reflectY( void )
{
}

void Vector2D::truncate( float )
{
}

void Vector2D::rotate( float )
{
}

Vector2D Vector2D::getLeftOrtho( void )
{
}

Vector2D Vector2D::getRightOrtho( void )
{
}

Vector2D Vector2D::getNormalized( void )
{
}

void Vector2D::setLeftOrtho( void )
{
}

void Vector2D::setRightOrtho( void )
{
}
	
float Vector2D::dot( Vector2D )
{
}

Vector2D Vector2D::operator - ( const Vector2D& ) const
{
}

Vector2D& Vector2D::operator -= ( const Vector2D& )
{
}

Vector2D Vector2D::operator + ( const Vector2D& ) const
{
}

Vector2D& Vector2D::operator += ( const Vector2D& )
{
}

Vector2D Vector2D::operator * ( const float ) const
{
}

Vector2D Vector2D::operator *= ( float )
{
}

Vector2D Vector2D::operator /  ( const float ) const
{
}

Vector2D Vector2D::operator /= ( float )
{
}

Vector2D Vector2D::scalePlus( const float, const Vector2D& ) const
{
}

void Vector2D::scalePlusEquals( const float, const Vector2D& )
{
}

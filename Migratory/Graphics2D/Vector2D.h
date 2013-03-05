#include "XYPair.h"

using namespace std;

class Vector2D :
	public XYPair
{
public:
	static const Vector2D ZERO_VEC;

	Vector2D( void );
	Vector2D( float, float );
	Vector2D( XYPair, XYPair);
	~Vector2D(void);

	float angle( void );	
	float magnitude( void );
	float magnitudeSq( void );
	
	void negate( void );
	void normalize( void );
	void reflectX( void );
	void reflectY( void );
	void truncate( float );
	void rotate( float );

	Vector2D getLeftOrtho( void );
	Vector2D getRightOrtho( void );
	Vector2D getNormalized( void );

	void setLeftOrtho( void );
	void setRightOrtho( void );
	
	float dot( Vector2D );

	Vector2D operator - ( const Vector2D& ) const;
	Vector2D& operator -= ( const Vector2D& );
	Vector2D operator + ( const Vector2D& ) const;
	Vector2D& operator += ( const Vector2D& );
	Vector2D operator * ( const float ) const;
	Vector2D& operator *= ( const float );
	Vector2D operator / ( const float ) const;
	Vector2D& operator /= ( const float );
	

	Vector2D scalePlus( const float, const Vector2D& ) const;
	void scalePlusEquals( const float, const Vector2D& );
};


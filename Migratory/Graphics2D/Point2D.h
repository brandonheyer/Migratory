#include "Vector2D.h"

using namespace std;

class Point2D :
	public XYPair
{
public:
	static const Point2D ZERO_POINT;

	Point2D( void );
	Point2D( float, float );
	~Point2D(void);

	Vector2D operator - ( const Point2D& ) const;
	Point2D operator + ( const Vector2D& ) const;
	Point2D& operator += ( const Vector2D& );

	Point2D scalePlus( const float, const Vector2D& ) const;
	void scalePlusEquals( const float, const Vector2D& );
};


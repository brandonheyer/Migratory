using namespace std;

class XYPair
{
public:
	static const float TOL;

	XYPair( void );
	XYPair( float, float );
	~XYPair( void );

	XYPair operator = (XYPair);
	bool operator == (XYPair);

	float getX( void ) const;
	float getY( void ) const;

	void set( float, float );
	void setX( float );
	void setY( float );

protected:
	float _x;
	float _y;
};

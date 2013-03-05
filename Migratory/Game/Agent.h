#include "../IndieLib/IND_Entity2d.h"
#include "../Graphics2D/Point2D.h"

using namespace std;

class Agent : 
	public IND_Entity2d
{
public:
	Agent( void );

	Agent( Point2D& );
	~Agent( void );

	virtual void update( float ) = 0;

	Point2D getLocation( void );
	Point2D getDestination( void );
	float getRadius( void );
	float getSpeed( void );
	Vector2D getHeading( void );

	void setLocation( Point2D& );
	void setDestination( Point2D& );
	void setRadius( float );
	void setSpeed( float );
	void setHeading( Vector2D& );

protected:
	Point2D _location;
	Point2D _destination;
	Vector2D _heading;
	
	float _speed;
	float _radius;
};


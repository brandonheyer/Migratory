#pragma once
class Point
{
private:
	int _x;
	int _y;
public:
	Point( void );
	Point( int, int );
	~Point(void);

	int getX( void );
	int getY( void );
	
	void setX( int );
	void setY( int );
};


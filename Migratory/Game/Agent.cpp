#include "Agent.h"


Agent::Agent(void)
{
	this->_location = Point2D();
	this->_destination = Point2D();
	this->_heading = Vector2D();
	this->_speed = 0;
	this->_radius = 0;
}

Agent::Agent( Point2D& p )
{
	this->_location = Point2D( p );
	this->_destination = Point2D();
	this->_heading = Vector2D();
	this->_speed = 0;
	this->_radius = 0;
}

Agent::~Agent(void)
{
}

Point2D Agent::getLocation( void )
{
	return this->_location;
}

Point2D Agent::getDestination( void )
{
	return this->_destination;
}

float Agent::getRadius( void )
{
	return this->_radius;
}

float Agent::getSpeed( void )
{
	return this->_speed;
}

Vector2D Agent::getHeading( void )
{
	return this->_heading;
}

void Agent::setLocation( Point2D& p )
{
	this->_location = p;
}

void Agent::setDestination( Point2D& p )
{
	this->_destination = p;
}

void Agent::setRadius( float r )
{
	this->_radius = r;
}

void Agent::setSpeed( float s )
{
	this->_speed = s;
}

void Agent::setHeading( Vector2D& v )
{
	this->_heading = v;
}
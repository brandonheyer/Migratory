#include "BoidAgent.h"


BoidAgent::BoidAgent(void)
{
}

BoidAgent::BoidAgent( Point2D& p )
{
	this->_location = p;
	this->_speed = 5000;
	this->_radius = 5;
	this->_heading = Vector2D( 1, 1 );
	this->_heading.normalize();
}

BoidAgent::~BoidAgent(void)
{
}

void BoidAgent::update( float delta ) {
	this->_location.scalePlusEquals( this->_speed * delta, this->_heading );
};

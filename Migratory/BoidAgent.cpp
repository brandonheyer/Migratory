#include "BoidAgent.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


BoidAgent::BoidAgent(void)
{
}

BoidAgent::BoidAgent( Point2D& p, bool randomHeading )
{
	this->_location = p;
	this->_speed = 25;
	this->_radius = 5;


	if ( randomHeading ) {
		this->_heading = Vector2D( ( ( rand() % 20 ) - 10.0f ) / 10.0f, ( ( rand() % 20 ) - 10.0f ) / 10.0f );
	} else {
		this->_heading = Vector2D( 1, 1 );
	}

	this->_heading.normalize();
}

BoidAgent::~BoidAgent(void)
{
}

void BoidAgent::update( float delta ) {
	this->_location.scalePlusEquals( this->_speed * delta, this->_heading );
};

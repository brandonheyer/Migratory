#include "BoidAgent.h"

BoidAgent::BoidAgent(void)
{
	this->_initialize( Point2D( 0, 0 ), Vector2D( 1, 1 ) );
}

BoidAgent::BoidAgent( Point2D& p ) {
	this->_initialize( p, Vector2D( 1, 1 ) );
}

BoidAgent::BoidAgent( Point2D& p, Vector2D& heading )
{
	this->_initialize( p, heading );
}

void BoidAgent::_initialize( Point2D& p, Vector2D& h ) {
	this->_heading = h;
	this->_location = p;
	this->_speed = 100;
	this->_radius = 5;
	this->_heading.normalize();
}

BoidAgent::~BoidAgent(void)
{
}

void BoidAgent::update( float delta ) {
	this->_location.scalePlusEquals( this->_speed * delta, this->_heading );
};

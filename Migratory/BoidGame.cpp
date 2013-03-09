#include "BoidGame.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

BoidGame::BoidGame(void)
{
	srand( time( NULL ) );
}


BoidGame::~BoidGame(void)
{
	BoidAgent* boid;

	for ( std::vector<BoidAgent*>::iterator it = this->boids.begin(); it != this->boids.end(); ++it )
	{
		boid = *it;
		delete boid;
	}
	
	this->boids.clear();
}

BoidAgent* BoidGame::addBird( void )
{
	BoidAgent* boid = new BoidAgent( 
		Point2D( rand() % 800, rand() % 600 ),
		Vector2D( ( ( rand() % 20 ) - 10.0f ) / 10.0f, ( ( rand() % 20 ) - 10.0f ) / 10.0f )
	);

	this->boids.push_back( boid );
	this->alignment.push_back( new Vector2D( 0, 0 ) );
	this->cohesion.push_back( new Vector2D( 0, 0 ) );
	this->separation.push_back( new Vector2D( 0, 0 ) );

	return boid;
}
	
void BoidGame::update( float delta )
{
	Point2D position;
	float xPos;
	float yPos; 
	BoidAgent * boid, * match;
	unsigned i, j;
	Vector2D* alignment;
	Vector2D* cohesion;
	Vector2D* separation;
	Vector2D temp;

	float matchLocX, matchLocY, magnitude;

	for ( i = 0; i < this->boids.size(); i++ )
	{
		boid = this->boids[ i ];
		alignment = this->alignment[ i ];
		cohesion = this->cohesion[ i ];
		separation = this->separation[ i ];

		alignment->setX( 0 );
		alignment->setY( 0 );

		cohesion->setX( 0 );
		cohesion->setY( 0 );

		separation->setX( 0 );
		separation->setY( 0 );

		for ( j = 0; j < this->boids.size(); j++ ) {
			match = this->boids[ j ];

			temp = *( match->getHeading() );
			temp *= match->getSpeed();
			*alignment += temp;

			matchLocX = match->getLocation()->getX();
			matchLocY = match->getLocation()->getY();

			temp.setX( matchLocX );
			temp.setY( matchLocY );
			*cohesion += temp;

			temp.setX( boid->getLocation()->getX() - matchLocX );
			temp.setY( boid->getLocation()->getY() - matchLocY );
			magnitude = temp.magnitude();

			if ( magnitude != 0 ) {
				separation->scalePlusEquals( 1.0f / magnitude, temp );
			}
		}

		*alignment /= this->boids.size() + 0.0f;
		*cohesion /= this->boids.size() + 0.0f;

		cohesion->setX( cohesion->getX() - boid->getLocation()->getX() );
		cohesion->setY( cohesion->getY() - boid->getLocation()->getY() );
	}

	for ( i = 0; i < this->boids.size(); i++ )
	{
		boid = this->boids[ i ];
		alignment = this->alignment[ i ];
		cohesion = this->cohesion[ i ];
		separation = this->separation[ i ];

		alignment->normalize();
		cohesion->normalize();
		separation->normalize();

		*alignment /= 10000;
		*cohesion /= 50;
		*separation /= 500;

		temp = *( boid->getHeading() );
		temp += *alignment;
		temp += *cohesion;
		temp += *separation;
		temp.normalize();
		boid->setHeading( temp );

		boid->update( delta );

		position = *( boid->getLocation() );
		xPos = position.getX();
		yPos = position.getY();
		
		if ( xPos < 0 ) {
			xPos += 800.0f;
		}

		if ( yPos < 0 ) {
			yPos += 600.0f;
		}

		xPos = fmod( xPos, 800.0f );
		yPos = fmod( yPos, 600.0f );

		boid->setLocation( Point2D( xPos, yPos ) );
		boid->setAngleXYZ( 0, 0, boid->getHeading()->angle() * 180.0f / 3.141f + 90.0f );
	}
}
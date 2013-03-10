#include "BoidGame.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

BoidGame::BoidGame(void)
{
	srand( time( NULL ) );

	this->alignmentAmount = 500;
	this->cohesionAmount = 50;
	this->separationAmount = 50;
	this->matchRadius = 100;
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
		Point2D( rand() % 1024, rand() % 768 ),
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

		matches.clear();

		alignment->setX( 0 );
		alignment->setY( 0 );

		cohesion->setX( 0 );
		cohesion->setY( 0 );

		separation->setX( 0 );
		separation->setY( 0 );

		for ( j = 0; j < this->boids.size(); j++ ) {
			if ( i == j ) {
				continue;
			}

			match = this->boids[ j ];
			temp.setX( match->getLocation()->getX() - boid->getLocation()->getX() );
			temp.setY( match->getLocation()->getY() - boid->getLocation()->getY() );

			if ( temp.magnitudeSq() <= this->matchRadius * this->matchRadius ) {
				this->matches.push_back( match );
			}
		}

		for ( j = 0; j < this->matches.size(); j++ ) {
			match = this->matches[ j ];

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

		if ( this->matches.size() >= 1 ) {
			*alignment /= this->matches.size() + 0.0f;
			*cohesion /= this->matches.size() + 0.0f;
		}

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

		*alignment /= this->alignmentAmount;
		*cohesion /= this->cohesionAmount;
		*separation /= this->separationAmount;

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
			xPos += 1024.0f;
		}

		if ( yPos < 0 ) {
			yPos += 768.0f;
		}

		xPos = fmod( xPos, 1024.0f );
		yPos = fmod( yPos, 768.0f );

		boid->setLocation( Point2D( xPos, yPos ) );
		boid->setAngleXYZ( 0, 0, boid->getHeading()->angle() * 180.0f / 3.141f + 90.0f );
	}
}
	
void BoidGame::increaseAlignment( void )
{
	alignmentAmount -= 5;
}

void BoidGame::increaseCohesion( void )
{
	cohesionAmount -= 5;
}

void BoidGame::increaseSeparation( void )
{
	separationAmount -= 5;
}

void BoidGame::decreaseAlignment( void )
{
	this->alignmentAmount += 5;
}

void BoidGame::decreaseCohesion( void )
{
	this->cohesionAmount += 5;
}

void BoidGame::decreaseSeparation( void )
{
	this->separationAmount += 5;
}
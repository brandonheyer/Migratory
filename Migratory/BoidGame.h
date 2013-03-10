#pragma once
#include <vector>
#include "BoidAgent.h"

class BoidGame
{
public:
	BoidGame( void );
	~BoidGame( void );

	BoidAgent* addBird( void );
	void update( float );

	void increaseAlignment( void );
	void increaseCohesion( void );
	void increaseSeparation( void );

	void decreaseAlignment( void );
	void decreaseCohesion( void );
	void decreaseSeparation( void );

private:
	std::vector<BoidAgent*> boids;
	std::vector<BoidAgent*> matches;

	std::vector<Vector2D*> alignment;
	std::vector<Vector2D*> cohesion;
	std::vector<Vector2D*> separation;

	float alignmentAmount;
	float cohesionAmount;
	float separationAmount;
	float matchRadius;
};


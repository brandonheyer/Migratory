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

private:
	std::vector<BoidAgent*> boids;

	std::vector<Vector2D*> alignment;
	std::vector<Vector2D*> cohesion;
	std::vector<Vector2D*> separation;
};


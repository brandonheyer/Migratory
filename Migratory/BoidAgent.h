#pragma once
#include "game/agent.h"

class BoidAgent :
	public Agent
{
public:
	BoidAgent(void);
	BoidAgent( Point2D& );
	BoidAgent( Point2D&, Vector2D& );

	~BoidAgent(void);

	void update( float );

private:
	void _initialize( Point2D&, Vector2D& );
};


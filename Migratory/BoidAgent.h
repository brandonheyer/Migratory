#pragma once
#include "game/agent.h"

class BoidAgent :
	public Agent
{
public:
	BoidAgent(void);
	BoidAgent( Point2D& );

	~BoidAgent(void);

	void update( float );
};


#pragma once
#include "d:\projects\indielib\personal\migratory\migratory\game\agent.h"
class BoidAgent :
	public Agent
{
public:
	BoidAgent(void);
	BoidAgent( Point2D& );

	~BoidAgent(void);

	void update( float );
};


/*****************************************************************************************
 * Desc: Tutorials a) 08 Collisions
 *****************************************************************************************/

#include "CIndieLib_vc2008.h"

#include "IndieLib/IND_Surface.h"
#include "IndieLib/IND_Animation.h"
#include "IndieLib/IND_Font.h"
#include "WorkingPath.h"
#include "BoidAgent.h"
#include "BoidGame.h"

#include <stdio.h>

/* 
==================
Main
==================
*/
int IndieLib()
{
    //Sets the working path as the 'exe' directory. All resource paths are relative to this directory
	if (!WorkingPathSetup::setWorkingPathFromExe(NULL)) {
		std::cout<<"\nUnable to Set the working path !";
	}
	
	// ----- IndieLib intialization -----

	CIndieLib *mI = CIndieLib::instance();
	if ( !mI->init() ) return 0;									

	// ----- Surface loading -----

	// Loading Background
	IND_Surface *mSurfaceBoid = new IND_Surface();
	if ( !mI->_surfaceManager->add( mSurfaceBoid, "../res/boid.png", IND_ALPHA, IND_32) ) return 0;

	// ----- Set the surfaces into 2d entities ----
	BoidGame boidGame;
	BoidAgent *boid;
	
	for( int i = 0; i < 200; i++ ) {
		boid = boidGame.addBird();
		mI->_entity2dManager->add( boid );					// Entity adding
		boid->setSurface( mSurfaceBoid );					// Set the surface into the entity
	}

	while ( !mI->_input->onKeyPress(IND_ESCAPE) && !mI->_input->quit() )
	{
		// ----- Input update ----
		if ( mI->_input->isKeyPressed( IND_Q ) ) {
			boidGame.decreaseAlignment();
		} else if ( mI->_input->isKeyPressed( IND_W ) ) {
			boidGame.increaseAlignment();
		} else if ( mI->_input->isKeyPressed( IND_A ) ) {
			boidGame.decreaseCohesion();
		} else if ( mI->_input->isKeyPressed( IND_S ) ) {
			boidGame.increaseCohesion();
		} else if ( mI->_input->isKeyPressed( IND_Z ) ) {
			boidGame.decreaseSeparation();
		} else if ( mI->_input->isKeyPressed( IND_X ) ) {
			boidGame.increaseSeparation();
		}

		mI->_input->update();
		boidGame.update( mI->_render->getFrameTime() / 1000.0f );

		// ----- Render  -----
		mI->_render->beginScene();
		mI->_render->clearViewPort(255, 255, 255);
		mI->_entity2dManager->renderEntities2d();
		mI->_render->endScene();	
	}

	// ----- Free -----

	mI->end();

	return 0;
}

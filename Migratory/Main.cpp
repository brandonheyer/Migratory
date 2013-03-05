/*****************************************************************************************
 * Desc: Tutorials a) 08 Collisions
 *****************************************************************************************/

#include "CIndieLib_vc2008.h"

#include "IndieLib/IND_Surface.h"
#include "IndieLib/IND_Animation.h"
#include "IndieLib/IND_Font.h"
#include "WorkingPath.h"
#include "BoidAgent.h"

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

	// ----- Set the surfaces into 2d entities -----

	// Creating 2d entity for the Rocket
	BoidAgent *mBoid = new BoidAgent( Point2D( 400, 300 ) );					
	mI->_entity2dManager->add( mBoid );					// Entity adding
	mBoid->setSurface( mSurfaceBoid );					// Set the surface into the entity


	// ----- Changing the attributes of the 2d entities -----

	// ----- Main Loop -----

	float mAngle = 0;
	float mScale = 1.0f;
	int mSpeedRotation = 5;
	int mSpeedScaling = 1;
	float mDelta;

	float mPosX;
	float mPosY;

	Point2D position;

	float width = 800;
	float height = 600;

	while ( !mI->_input->onKeyPress(IND_ESCAPE) && !mI->_input->quit() )
	{
		// ----- Input update ----

		mI->_input->update();

		// ----- Input ----

		mDelta = mI->_render->getFrameTime() / 1000.0f;

		//mBoid->update( mDelta );

		position = mBoid->getLocation();
		mPosX = position.getX();
		mPosY = position.getY();
		
		mPosX = fmod( mPosX + 1, width );
		mPosY = fmod( mPosY + 1, height );

		cout << mPosX << endl;

		// ----- Updating entities attributes  -----
		//mBoid->setAngleXYZ (0, 0, mAngle);

		mBoid->setLocation( Point2D( mPosX, mPosY ) );

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

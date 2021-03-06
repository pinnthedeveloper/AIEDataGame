#pragma once
#include "Vector2.h"

//forward decleration
class Application2D;

/*
* class GameState
*
* abstract class for a snapshot of a game that can be
* changed dynamically over time
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class GameState
{
public:

	bool firstFrame = false; //don't allow the gamestate to immediately take updates as soon as it's added
	bool isFinalUpdate = true; //indicates if this state is the final state to update
	bool isFinalDraw = true; //indicates if this state is the final state to draw

	Vector2 cameraOverride = Vector2(0, 0); //the position that the camera should be at when drawing this state

	/*
	* GameState
	* default constructor
	*/
	GameState() {};

	/*
	* GameState
	* virtual function
	* default destructor
	*/
	virtual ~GameState() {};

	/*
	* update
	* abstract function
	*
	* simulates one frame of the gamestate
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	virtual void update(Application2D* appPtr, float deltaTime) = 0;

	/*
	* draw
	* abstract function
	*
	* renders the gamestate
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @returns void
	*/
	virtual void draw(Application2D* appPtr) = 0;

	/*
	* onEnter
	* abstract function
	*
	* called when the gamestate becomes the uppermost gamestate in the stack
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @returns void
	*/
	virtual void onEnter(Application2D* appPtr) = 0;

	/*
	* onExit
	* abstract function
	*
	* called when the gamestate is no longer the uppermost gamestate in the stack
	*
	* @param Application2D* appPtr - pointer to the application that contains the stack that this gamestate is stored in
	* @returns void
	*/
	virtual void onExit(Application2D* appPtr) = 0;
};
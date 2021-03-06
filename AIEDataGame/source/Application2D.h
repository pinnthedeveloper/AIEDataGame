#pragma once
#include "Application.h"
#include "Renderer2D.h"

#include "ResourceManager.h"
#include "Input.h"
#include "Texture.h"
#include "Audio.h"

#include "Pool.h"

#include "Director.h"
#include "Builder.h"
#include "PlayerBuilder.h"
#include "EnemyBuilder.h"
#include "WallBuilder.h"
#include "LevelBuilder.h"
#include "FlagBuilder.h"

#include "MathLibrary.h"
#include "LinkedList.h"
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"

#include "Item.h"
#include "Button.h"
#include "Text.h"
#include "Timer.h"
#include "TickBox.h"
#include "Sprite.h"

#include "Action.h"
#include "PushAction.h"
#include "PopAction.h"
#include "FunctionAction.h"

/*
* class Application2D
* child class of aie::Application
*
* manages the game, provides a common access point for getting input
* rendering textures and updating entities in game loops
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class Application2D : public aie::Application
{
public:

	/*
	* Application2D()
	* constructor, does nothing but will do something later
	*/
	Application2D();

	/*
	* ~Application2D()
	* overrides aie::Application's ~Application()
	* destructor, does nothing but will do something later
	*/
	~Application2D() override;

	/*
	* startup
	* overrides aie::Application's startup()
	*
	* attempts to initialise the application
	*
	* @returns bool - indicates if the startup succeeded
	*/
	bool startup() override;

	/*
	* shutdown
	* overrides aie::Application's shutdown()
	*
	* deletes all memory used by the program, called before the application is destroyed
	*
	* @returns void
	*/
	void shutdown() override;

	/*
	* update
	* overrides aie::Application's update(float deltaTime)
	*
	* simulates one frame of the game
	*
	* @param float deltaTime - the amount of time passed since the last frame
	* @returns void
	*/
	void update(float deltaTime) override;

	/*
	* draw
	* overrides aie::Application's draw()
	*
	* renders all required textures to the screen
	*
	* @returns void
	*/
	void draw();

	aie::Renderer2D* m_renderer2D; //draws everything

	//frame-rate limiters
	float maxFrame = 1 / 30.0f;
	float minFrame = 1 / 120.0f;

	//previous state variables
	bool PREV_MOUSE_0_STATE = false;
	bool PREV_MOUSE_1_STATE = false;

	Vector2 m_screen = Vector2(0, 0); //dimensions of the screen

	Pool* m_pool; //pool for all objects registered to it

	Director* director; //controls builders
	PlayerBuilder* playerBuilder; //builder that spawns players
	EnemyBuilder* enemyBuilder; //builder that spawns enemies
	WallBuilder* wallBuilder; //builder that spawns walls
	LevelBuilder* levelBuilder; //builder that spawns level grids
	FlagBuilder* flagBuilder; //builder that spawns flags


	LinkedList<GameState*> gameStateStack; //gamestate stack, contains game states layered on top of each other
	LinkedList<GameState*> gameStateList; //global gamestate list, keeps all gamestates as static pointers

	LinkedList<Item*> elements; //list of items that the game is using
	LinkedList<Action*> actions; //list of actions that the game is using

};
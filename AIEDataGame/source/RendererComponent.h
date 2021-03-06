#pragma once
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "LinkedList.h"
#include "AABB.h"
#include "TextureResource.h"

//forward declaration
class Application2D;

/*
* class RendererComponent
* child class of BaseComponent
*
* a component that holds a position
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class RendererComponent : public BaseComponent
{
public:

	LinkedNode<RendererComponent*>* thisNode = nullptr; //position in the renderers array in playState

	TextureResource* textureRes; //the texture that the renderer can render
	AABB region; //the region to render to

	/*
	* RendererComponent()
	* default constructor
	*/
	RendererComponent() {};

	/*
	* ~RendererComponent()
	* destructor, releases the texture
	*/
	~RendererComponent();

	/*
	* initialise
	* overrides BaseComponent's initialise()
	*
	* initialises the component, only gets called if component is attached to a gameobject
	*
	* @returns void
	*/
	void initialise() override;

	/*
	* render
	* 
	* draws the texture to the screen
	*
	* @param Application2D* appPtr - pointer to the application that will render it
	* @param Vector2 cameraOffset - offset from the origin to draw the texture from in addition to transforms
	* @returns void
	*/
	void render(Application2D* appPtr, Vector2 cameraOffset);

	/*
	* getGlobalAABB
	*
	* gets the true aabb that the
	* renderer's region is currently occupying
	* by adding the transform to the AABB
	*
	* @returns AABB - the global AABB
	*/
	AABB getGlobalAABB();

	/*
	* release
	*
	* releases all resources held
	* by the component
	*
	* @returns void
	*/
	void release();


};
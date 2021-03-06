#pragma once
#include "KeyList.h"
#include "Resource.h"
#include "TextureResource.h"
#include "FontResource.h"
#include "TextFileResource.h"

#define RESOURCE_MAN ResourceManager::getInstance()

//types of resources that can exist
enum class ResourceType
{
	TEXTURE,
	AUDIO,
	FONT,
	TEXTFILE,
};

/*
* class ResourceReference
*
* couples a resource with a count of the amount
* of uses the resource currently has
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class ResourceReference
{
public:

	/*
	* ResourceReference
	* default constructor
	*/
	ResourceReference() {}

	/*
	* ~ResourceReference()
	* destructor, releases the aquired data for the resource and then
	* frees the resource object itself
	*/
	~ResourceReference()
	{
		resource->releaseResource();
		delete resource;
	}

	Resource* resource = nullptr;
	unsigned int resourceCount;
};

/*
* class ResourceManager
*
* a singleton class that manages all loaded files
* by creating and destroying them dynamically depending on
* what objects require them (basic pooling)
*
* author: Bradley Booth, Academy of Interactive Entertainment, 2017
*/
class ResourceManager
{
public:

	char resourcePath[MAX_PATH]; //path to the resource folder

	KeyList<ResourceReference*> loadedContainer; //contains resource objects

	/*
	* getInstance
	*
	* gets the pointer to the ResourceManager singleton, creates
	* the singleton if it doesn't exist already
	*
	* @returns static ResourceManager* - the singleton pointer
	*/
	static ResourceManager* getInstance();

	/*
	* initialise
	*
	* sets up the resource manager for managing resources
	*
	* @returns void
	*/
	void initialise();

	/*
	* requestResource
	*
	* creates the resource if it is not being used
	* merely hands the pointer back if the requested
	* resource has already been created
	*
	* @param ResourceType resourceType - the type of resource to load
	* @param fileName[MAX_PATH] - c-string of the file path
	* @returns Resource* - the resource requested
	*/
	Resource* requestResource(ResourceType type, char fileName[MAX_PATH]);

	/*
	* releaseResource
	*
	* delete the resource if the object releasing it is the last
	* object using the resource, does nothing otherwise
	*
	* @param fileName[MAX_PATH] - c-string of the file path
	* @returns void
	*/
	void releaseResource(char fileName[MAX_PATH]);

private:

	//hide the constructor and destructor

	/*
	* ResourceManager
	* default constructor
	*/
	ResourceManager() {};

	/*
	* ~ResourceManager
	* default destructor
	*/
	~ResourceManager() {}

};

#pragma once
// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "typedefs/types.h"
#include "typedefs/utils.h"
#include "systems/console.h"
#include "systems/filesystem.h"


//Forward declarations.
class Window;
class Renderer;
class Gameobject;
class Camera;

//Class Application
class Application
{
	//Define Application as a singleton. See utils.h for definition.
	DEFINE_SINGLETON(Application)

//Declare public functions.
public:
	void Initialize(char* title, iVec2 resolution, ui32 displayID = 0);
	void Update(void);
	void CleanUp(void);
	Filesystem* GetFilesystem();
//Declare private variables
private:
	Filesystem* filesystem;
	Renderer* renderer;
	Gameobject* root;
};
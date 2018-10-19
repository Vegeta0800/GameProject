
// EXTERNAL INCLUDES
// INTERNAL INCLUDES
#include "application.h"
#include "scene/gameobject.h"
#include "components/movement.h"
#include "rendering/renderer.h"
#include "rendering/shader.h"
#include "systems/console.h"

//Declare Application as a Singleton.
DECLARE_SINGLETON(Application)

//Void Initialize
void Application::Initialize(char* title, iVec2 resolution, ui32 displayID)
{
	//Instantiate the window.
	Window::GetInstance().Instantiate(title, resolution.x, resolution.y, displayID);

	//Create the scenegraph root.
	this->root = new Gameobject;
	this->root->SetName("root");
	this->root->MakeRoot();

	//Create gameobjects.
	Gameobject* player1 = new Gameobject;
	Gameobject* player2 = new Gameobject;
	Gameobject* player3 = new Gameobject;
	Gameobject* player4 = new Gameobject;

	//Set gameobjects names.
	player1->SetName("player1");
	player2->SetName("player2");
	player3->SetName("player3");
	player4->SetName("player4");

	//Add childs.
	this->root->AddChild(player1);
	player1->AddChild(player2);
	player1->AddChild(player3);
	player2->AddChild(player4);

	//Create and initialize a new movment component.
	Movement* mov = new Movement;
	mov->Initialize("movement", ComponentType::Movement);

	//Add player1 the movement component.
	player1->AddComponent(mov);

	//Create and initialize the renderer.
	Application::renderer = new Renderer;
	Application::filesystem = new Filesystem;
	Application::renderer->Initialize(displayID);
}

//Void Update
void Application::Update(void)
{
	//Do loop.
	do
	{
		// Pump window messages
		Window::GetInstancePtr()->DispatchMessages();

		//If escape key, close window.
		if (GetAsyncKeyState(VK_ESCAPE))
			break;

		// Update Gamestate
		this->root->Update();
		// Render Gamestate
		Application::renderer->Render();

	} while (true);
}

//Void Cleanup
void Application::CleanUp(void)
{
	//Release all pointers and safe delete the renderer
	Application::renderer->CleanUp();
	Console::GetInstancePtr()->CleanUp();
	SAFE_DELETE(this->renderer);
	Console::GetInstancePtr()->Release();
	Window::GetInstancePtr()->Release();
	Application::GetInstancePtr()->Release();
}

Filesystem* Application::GetFilesystem()
{
	return this->filesystem;
}

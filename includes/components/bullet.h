#pragma once
//EXTERNAL INCLUDES
#include <thread>
//INTERNAL INCLUDES
#include "component.h"

//Class Movement that is derived from class Component.
class Bullet : public Component
{
	//Declare the public functions that are overwritten.
public:
	Bullet();

	void Initialize(Gameobject* gb);
	virtual void Update(void) override;
	virtual void Cleanup(void) override;
	BulletValues& GetBulletValues(void);

private:
	void Deflect(void);
	bool deflecting = false;
	std::thread mirrorThread;
	BulletValues bullet;
};
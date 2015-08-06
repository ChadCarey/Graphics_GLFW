#include "IRunnable.h"
#include "Engine.h"
#include "CubeTexture.h"

class DrawCube : public IRunnable
{
	virtual void run() override;
};
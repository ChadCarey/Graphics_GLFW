#pragma once
#include "InitGlut.h"
#include "SceneManager.h"
using namespace Core;

int main(int argc, char **argv)
{
	WindowInfo window(std::string("OpenGL window"), 
		400, 200, // position
		800, 600, // size
		true);    // reshape
	
	ContextInfo context(4, 2, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	Init_GLUT::init(window, context, frameBufferInfo);
	
	IListener* scene = new Managers::SceneManager();
	Init_GLUT::setListener(scene);

	Init_GLUT::run();

	// Clean up
	delete scene;
	return 0;
}
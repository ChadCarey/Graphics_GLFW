#pragma once
#include "InitGlut.h"
using namespace Core;

int main(int argc, char **argv)
{
	WindowInfo window(std::string("in2gpu OpenGL Beginner Tutorial "), 
		400, 200, // position
		800, 600, // size
		true);    // reshape

	ContextInfo context(4, 5, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);
	Init_GLUT::init(window, context, frameBufferInfo);

	Init_GLUT::run();

	return 0;
}
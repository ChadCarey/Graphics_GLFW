#pragma once
#include "ShaderManager.h"
#include "GameModels.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include <iostream>
using namespace Managers;

/**
* Graphics_Freeglut is an abstraction to openGL and the free glut library
* Resources:
*	Basic openGL: http://in2gpu.com/2014/10/17/creating-opengl-window/
*	Wrappers for C methods: https://github.com/PaulSolt/GLUT-Object-Oriented-Framework/blob/master/src/GlutFramework.h
*							http://stackoverflow.com/questions/3589422/using-opengl-glutdisplayfunc-within-class (answer from shox_de_coder)
*/


Models::GameModels* gameModels;
GLuint program;
ShaderManager* shaderManager;

std::string findOpenGLVersion()
{
	std::string version = "none";

	if (glewIsSupported("GL_VERSION_4_5"))
	{
		version = "GL_VERSION_4_5";
	}
	else if (glewIsSupported("GL_VERSION_4_4"))
	{
		version = "GL_VERSION_4_4";
	}
	else if (glewIsSupported("GL_VERSION_4_3"))
	{
		version = "GL_VERSION_4_3";
	}
	else if (glewIsSupported("GL_VERSION_4_2"))
	{
		version = "GL_VERSION_4_2";
	}
	else if (glewIsSupported("GL_VERSION_4_1"))
	{
		version = "GL_VERSION_4_1";
	}
	else if (glewIsSupported("GL_VERSION_4_0"))
	{
		version = "GL_VERSION_4_0";
	}

	std::cout << " GL Version is " << version << std::endl;
	return version;
}

void renderScene(void)
{
	// tells OpenGL to clear its buffers. In our case Depth and Color. To clear them simultaneously we OR them
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// specify clear values for color buffers. These values must be between 0.0 and 1.0. Arguments are : red, green, blue, alpha.
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// bind our vertex array
	glBindVertexArray(gameModels->GetModel("triangle1"));


	//use the created shader program
	glUseProgram(program);

	//draw 3 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 3);
	// swaps between back buffer and front buffer. Remember that we are using double buffering.
	glutSwapBuffers();
}

void closeCallback()
{

	std::cout << "GLUT:\t Finished" << std::endl;
	glutLeaveMainLoop();
}

void Init()
{

	glEnable(GL_DEPTH_TEST);

	gameModels = new Models::GameModels();
	gameModels->CreateTriangleModel("triangle1");

	//load and compile shaders
	shaderManager = new ShaderManager();
	shaderManager->CreateProgram("colorShader", "Vertex_Shader.glsl",
		"Fragment_Shader.glsl");
	program = ShaderManager::GetShader("colorShader");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{
	// set up the display window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(400, 100); //optional
	glutInitWindowSize(800, 600); //optional
	glutCreateWindow("OpenGL First Window");
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	// inicialize glew and find what version this card can use
	glewInit();
	findOpenGLVersion();

	// inicialize shader program
	Init();
	// register drawing callbacks
	glutDisplayFunc(renderScene);
	glutCloseFunc(closeCallback);

	glutMainLoop();

	// delete globals (look for a way to make them not global later)
	delete gameModels;
	delete shaderManager;
	glDeleteProgram(program);
	return 0;
}
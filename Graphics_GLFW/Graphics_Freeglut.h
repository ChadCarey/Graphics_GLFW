#pragma once
#include "GL/glew.h"
#include"GL/freeglut.h"
#include <iostream>
#include <string>
#include "ShaderLoader.h"
#include "GameModels.h"

/**
* Graphics_Freeglut is an abstraction to openGL and the free glut library
* Resources:
*	Basic openGL: http://in2gpu.com/2014/10/17/creating-opengl-window/ 
*	Wrappers for C methods: https://github.com/PaulSolt/GLUT-Object-Oriented-Framework/blob/master/src/GlutFramework.h
*							http://stackoverflow.com/questions/3589422/using-opengl-glutdisplayfunc-within-class (answer from shox_de_coder)
*/
class Graphics_Freeglut
{
public:
	Graphics_Freeglut();
	Graphics_Freeglut(int windowX, int windowY, int possitionX, int possitionY);
	void run(int argc, char* argv[]);
	void draw();
	void renderScene(void);

	// C function wrappers
	static void displayWrapper();
	static void closeWrapper();
private:
	int windowX, windowY, possitionX, possitionY;

	GLuint shaderProgram;
	Models::GameModels* gameModels;
	
	ShaderLoader shaderLoader;
	void initShaders();
	void closeCallback();

	std::string openGLVersion;
	std::string findOpenGLVersion();

};

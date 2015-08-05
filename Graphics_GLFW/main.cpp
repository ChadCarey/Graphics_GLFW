#pragma once
#include "InitGlut.h"
#include "SceneManager.h"
#include "Engine.h"
#include "ModelsManager.h"
#include "LameCube.h"
using namespace Core;

int main(int argc, char **argv)
{
	WindowInfo window(std::string("in2gpu OpenGL Chapter 2 tutorial"), 400, 200, 800, 600, true);
	ContextInfo context(4, 2, true);
	FramebufferInfo frameBufferInfo(true, true, true, true);

	Init_GLUT::init(window, context, frameBufferInfo);

	Managers::SceneManager* scene = new Managers::SceneManager();
	IListener* p = scene;
	Init_GLUT::setListener(p);

	Managers::ShaderManager shaderManager;
	shaderManager.createProgram("cubeShader",
		"Cube_Vertex_Shader.glsl",
		"Fragment_Shader.glsl");

	TextureLoader textureLoader;

	Managers::ModelsManager* modelsManager = new Managers::ModelsManager();

	scene->setModelsManager(modelsManager);
	Models::LameCube cube;
	cube.SetProgram(shaderManager.GetShader("cubeShader"));
	cube.Create();
	modelsManager->SetModel("square", &cube);
	Init_GLUT::run();
	
	// Clean up
	delete scene;
	delete modelsManager;
	return 0;
}
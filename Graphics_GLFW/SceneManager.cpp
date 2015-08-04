#include "SceneManager.h"
using namespace Managers;

SceneManager::SceneManager()
{
	glEnable(GL_DEPTH_TEST);

	shader_manager = new ShaderManager();
	shader_manager->CreateProgram("colorShader", "Vertex_Shader.glsl", "Fragment_Shader.glsl");
	models_manager = new ModelsManager();
}

SceneManager::~SceneManager()
{
	delete shader_manager;
	delete models_manager;
}

void SceneManager::notifyBeginFrame()
{

}

void SceneManager::notifyDisplayFrame()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	models_manager->Draw();
}

void SceneManager::notifyEndFrame()
{
}

void SceneManager::notifyReshape(int width, int height, int previous_width, int previous_height)
{

}
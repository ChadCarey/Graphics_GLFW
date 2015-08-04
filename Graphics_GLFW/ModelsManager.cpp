#include "ModelsManager.h"
using namespace Managers;

ModelsManager::ModelsManager()
{
	//by defaluts we are creating a triangle game object. Remove this later
	Models::Triangle* triangle = new Models::Triangle();
	triangle->SetProgram(ShaderManager::GetShader("colorShader"));
	triangle->Create();
	gameModelList["triangle"] = triangle;

	// square
	Models::Quad* quad = new Models::Quad();
	quad->SetProgram(ShaderManager::GetShader("colorShader"));
	quad->Create();
	gameModelList["quad"] = quad;
}

ModelsManager::~ModelsManager()
{
	//auto -it's a map iterator (LOOK THIS UP AND UNDERSTAND IT (C++11))
	for (auto model : gameModelList)
	{
		delete model.second;
	}
	gameModelList.clear();
}

void ModelsManager::DeleteModel(const std::string& gameModelName)
{
	IGameObject* model = gameModelList[gameModelName];
	model->Destroy();
	gameModelList.erase(gameModelName);
}

const IGameObject& ModelsManager::GetModel(const std::string& gameModelName) const
{
	return (*gameModelList.at(gameModelName));
}

void ModelsManager::Update()
{
	//auto -it's a map iterator (LOOK THIS UP AND UNDERSTAND IT (C++11))
	for (auto model : gameModelList)
	{
		model.second->Update();
	}
}

void ModelsManager::Draw()
{
	//auto -it's a map iterator (LOOK THIS UP AND UNDERSTAND IT (C++11))
	for (auto model : gameModelList)
	{
		model.second->Draw();
	}
}
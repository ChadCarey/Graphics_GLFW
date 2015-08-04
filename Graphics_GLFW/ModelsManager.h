#pragma once
#include <map>
#include "ShaderManager.h"
#include "IGameObject.h"
#include "Triangle.h"
#include "Quad.h"
using namespace Rendering;

namespace Managers
{
	class ModelsManager
	{
	public:
		ModelsManager();
		~ModelsManager();

		void Draw();
		void Update();
		void DeleteModel(const std::string& gameModelName);
		const IGameObject& GetModel(const std::string& gameModelName) const;

	private:
		std::map<std::string, IGameObject*> gameModelList; // This is not good practice because maps are not made for fast itterations, replace with a vector later once the engine is working
	};
}
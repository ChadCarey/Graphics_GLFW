#pragma once
#include <map>
#include "ShaderManager.h"
#include "IGameObject.h"
#include "Triangle.h"
#include "Quad.h"
using namespace Rendering;

typedef std::map<std::string, IGameObject*>::iterator model_map_it;

namespace Managers
{
	class ModelsManager
	{
	public:
		ModelsManager();
		~ModelsManager();

		void Draw();
		void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix);
		void Update();
		void DeleteModel(const std::string& gameModelName);
		const IGameObject& GetModel(const std::string& gameModelName) const;
		void DeleteModelNDC(const std::string& gameModelName);
		const IGameObject& GetModelNDC(const std::string& gameModelName) const;

		void SetModel(const std::string& gameObjectName, IGameObject* gameObject);

	private:
		std::map<std::string, IGameObject*> gameModelList; // This is not good practice because maps are not made for fast itterations, replace with a vector later once the engine is working
		std::map<std::string, IGameObject*> gameModelListNDC;
	};
}

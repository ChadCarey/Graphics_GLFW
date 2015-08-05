#pragma once
#include "InitGlut.h"
#include "SceneManager.h"
#include "TextureLoader.h"

namespace BasicEngine
{
	class Engine
	{

	public:
		Engine();
		~Engine();

		//OpenGL and manager init
		bool Init();

		//Loop
		void Run();

		//Getters
		Managers::SceneManager*  GetScene_Manager()  const;
		Managers::ShaderManager* GetShader_Manager() const;
		Managers::ModelsManager* GetModels_Manager() const;

		TextureLoader* GetTexture_Loader() const;
	private:
		Managers::SceneManager*  m_scene_manager;
		Managers::ShaderManager* m_shader_manager;
		Managers::ModelsManager* m_models_manager;

		TextureLoader* m_texture_loader;
	};
}
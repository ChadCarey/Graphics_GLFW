#pragma once
#include <vector>
#include "IGameObject.h"

namespace Models
{
	class Model :public Rendering::IGameObject
	{
	public:
		Model();
		virtual ~Model();
		// methods from interface
		virtual void Draw() override;
		virtual void Update() override;
		virtual void SetProgram(GLuint shaderName) override;
		virtual void Destroy() override;

		virtual GLuint GetVao() const override;
		virtual const std::vector<GLuint>& GetVbos() const override;

	protected:
		GLuint vao;
		GLuint program;
		std::vector<GLuint> vbos;
	};
}
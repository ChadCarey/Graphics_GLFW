#pragma once
#include <map>
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
		virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix) override;
		virtual void Update() override;
		virtual void SetProgram(GLuint shaderName) override;
		virtual void Destroy() override;

		virtual GLuint GetVao() const override;
		virtual const std::vector<GLuint>& GetVbos() const override;

		virtual void SetTexture(std::string textureName, GLuint texture) override;
		virtual const GLuint GetTexture(std::string textureName) const override;

	protected:
		std::map<std::string, GLuint> textures;
		GLuint vao;
		GLuint program;
		std::vector<GLuint> vbos;
	};
}

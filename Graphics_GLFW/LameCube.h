#pragma once
#include "Model.h"
#include<time.h>
#include<stdarg.h>
#include "VertexFormat.h"

/**
* draws a cube in the most inconvenient way possible: by creating the vertex array, triangle by triangle and passing it to the shader.
*/

namespace Models
{
	class LameCube : public Models::Model
	{
	public:
		LameCube();
		~LameCube();

		void Create();
		virtual void Draw(const glm::mat4& projection_matrix, const glm::mat4& view_matrix) override final;
		virtual void Update() override final;

	private:
		glm::vec3 rotation, rotation_speed;
		time_t timer;
	};
}
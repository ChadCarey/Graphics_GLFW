#ifndef  VertexFormat_H_
#define VertexFormat_H_

#include "glm\glm.hpp"

namespace Rendering
{

	struct VertexFormat
	{
		glm::vec3 position;//our first vertex attribute
		glm::vec4 color; // used to modify the color

		VertexFormat(const glm::vec3 &pos, const glm::vec4 &iColor)
		{
			position = pos;
			color = iColor;
		}
		
		VertexFormat() {}
	};

}

#endif
#include "GL/glew.h"
#include"GL/freeglut.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

/**
* 
* Resources: http://in2gpu.com/2014/10/29/shaders-basics/
*/
namespace Managers
{
	class ShaderManager
	{
	public:
		ShaderManager(void);
		~ShaderManager(void);
		void CreateProgram(const std::string& shaderName, const std::string& VertexShaderFilename, const std::string& FragmentShaderFilename);
		static const GLuint ShaderManager::GetShader(const std::string& shaderName) throw (std::string);
		static void ShaderManager::DeleteShader(const std::string& shaderName);

	private:
		std::string ReadShader(const std::string filename);
		GLuint CreateShader(GLenum shaderType, const std::string& source, const std::string& shaderName);
		static std::map<std::string, GLuint> programs;
	};
}
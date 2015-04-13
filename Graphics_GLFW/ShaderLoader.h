#include "GL/glew.h"
#include"GL/freeglut.h"
#include <iostream>
#include <string>
#include<fstream>
#include<vector>

/**
* 
* Resources: http://in2gpu.com/2014/10/29/shaders-basics/
*/
class ShaderLoader
{
public:
	ShaderLoader(void);
	~ShaderLoader(void);
	GLuint CreateProgram(std::string vertexShaderFilename, std::string fragmentShaderFilename);

private:
	std::string ReadShader(std::string filename);
	GLuint CreateShader(GLenum shaderType, std::string source, char* shaderName);
};
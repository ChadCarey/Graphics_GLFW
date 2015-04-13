#include "Graphics_Freeglut.h"

Graphics_Freeglut* instance;

Graphics_Freeglut::Graphics_Freeglut()
{
	this->windowX = 800;
	this->windowY = 600;
	this->possitionX = 200;
	this->possitionY = 200;
	instance = this;
}

Graphics_Freeglut::Graphics_Freeglut(int windowX, int windowY, int possitionX, int possitionY)
{
	this->windowX = windowX; 
	this->windowY = windowY;
	this->possitionX = possitionX; 
	this->possitionY = possitionY;
	instance = this;
}

void Graphics_Freeglut::draw()
{
	// tells OpenGL to clear its buffers. In our case Depth and Color. To clear them simultaneously we OR them
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// specify clear values for color buffers. These values must be between 0.0 and 1.0. Arguments are : red, green, blue, alpha.
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//use the created shader program
	glUseProgram(shaderProgram);

	//draw 3 vertices as triangles
	glDrawArrays(GL_TRIANGLES, 0, 3);

	// swaps between back buffer and front buffer. Remember that we are using double buffering.
	glutSwapBuffers();
}

void Graphics_Freeglut::initShaders()
{
	glEnable(GL_DEPTH_TEST);

	//load and compile shaders
	shaderProgram = shaderLoader.CreateProgram("Vertex_Shader.glsl", "Fragment_Shader.glsl");
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Graphics_Freeglut::run(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(possitionX, possitionY);//optional
	glutInitWindowSize(windowX, windowY); //optional
	glutCreateWindow("OpenGL First Window");

	// inicialize glew and find what version this card can use
	glewInit();
	this->openGLVersion = this->findOpenGLVersion();

	initShaders();
	
	// draw callback
	glutDisplayFunc(Graphics_Freeglut::displayWrapper);

	glutMainLoop();
	glDeleteProgram(shaderProgram);
}

std::string Graphics_Freeglut::findOpenGLVersion()
{
	std::string version = "none";

	if (glewIsSupported("GL_VERSION_4_5"))
	{
		version = "GL_VERSION_4_5";
	}
	else if (glewIsSupported("GL_VERSION_4_4"))
	{
		version = "GL_VERSION_4_4";
	}
	else if (glewIsSupported("GL_VERSION_4_3"))
	{
		version = "GL_VERSION_4_3";
	}
	else if (glewIsSupported("GL_VERSION_4_2"))
	{
		version = "GL_VERSION_4_2";
	}
	else if (glewIsSupported("GL_VERSION_4_1"))
	{
		version = "GL_VERSION_4_1";
	}
	else if (glewIsSupported("GL_VERSION_4_0"))
	{
		version = "GL_VERSION_4_0";
	}

	std::cout << " GLEW Version is " << version << std::endl;
	return version;
}

/*staic wrapper methods*/
void Graphics_Freeglut::displayWrapper()
{
	instance->draw();
}
#pragma once
#include <iostream>
#include "GL\glew.h"
#include "GL\freeglut.h"

namespace Core
{
		class InitGLEW
		{
		public:
			static void Init();
		private:
			static std::string findOpenGLVersion();
		};
}
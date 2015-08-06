#pragma once
#include "IRunnable.h"
#include "DrawCube.h"
using namespace BasicEngine;
using namespace Models;

int main(int argc, char **argv)
{
	IRunnable* runner = new DrawCube();
	runner->run();
	delete runner;
	
	return 0;
}
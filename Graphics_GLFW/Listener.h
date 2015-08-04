#pragma once

/**
* ref: http://in2gpu.com/2015/03/04/create-a-game-engine-part-iv-scene-manager/
*		"...passing SceneManager to Init_GLUT as a parameter is a bad practice because it creates an ugly dependency 
*		(maybe in the future we will want other scenes and/or other object to be notified). So it’s much better if 
*		we inject an interface in Init_GLUT and SceneManager implements this interface."
*/

namespace Core
{

	class IListener
	{
	public:
		virtual ~IListener() = 0;

		virtual void notifyBeginFrame() = 0; // physics time
		virtual void notifyDisplayFrame() = 0; // drawing time
		virtual void notifyEndFrame() = 0;
		virtual void notifyReshape(int width,
			int height,
			int previous_width,
			int previous_height) = 0;
	};

	inline IListener::~IListener(){
		//implementation of pure virtual destructor
	}
}
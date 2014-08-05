#ifndef PIOS
#define PIOS

#include <SDL2/SDL.h>
#include <Awesomium/WebCore.h>
#include <iostream>
#include "Time.h"
#include "window.h"

#define FRAME_CAP 5000
#define FRAME_TIME 1.0/FRAME_CAP



class Pios
{
public:
	Pios();
	~Pios();

	void run();

private:
	void Render();
	void Update();
	void Input();

private:
	Pios(const Pios& src){}
	void operator=(const Pios& src){}

private:
	//Window
	Window* window;

	//Flow controll
	bool m_isRunning;

	double lastTime;
	double unprocessedTime;

	bool render;
	double startTime;
	double passedTime;

	//Vars for calculating FPS
	int frames;
	double frameCounter;
};

#endif





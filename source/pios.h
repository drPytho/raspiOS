#ifndef PIOS
#define PIOS

#include <SDL2/SDL.h>
#include <Awesomium/WebCore.h>
#include <iostream>
#include "Time.h"
#include "input.h"

#define FRAME_CAP 5000
#define FRAME_TIME 1.0/FRAME_CAP



class Pios:public Input
{
public:
	Pios();
	~Pios();

	int run();
	int halt();

private:
	//void LoadInfo();
	void Render();
	void Update();
	void Input();

private:
	Pios(const Pios& src){}
	void operator=(const Pios& src){}

private:

	void actionKeyDown(SDL_Keysym& sym);
	void actionKeyUp(SDL_Keysym& sym);
	
	//SDL window
	SDL_Window* window;

	//SDL surface to draw on
	SDL_Surface* screen;

	//Flow controll
	bool isRunning;

	long lastTime;
	double unprocessedTime;

	bool render;
	long startTime;
	long passedTime;

	//Vars for calculating FPS
	int frames;
	long frameCounter;
};

#endif





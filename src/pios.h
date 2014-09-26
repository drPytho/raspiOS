#ifndef PIOS
#define PIOS

#include <SDL2/SDL.h>
#include <Awesomium/WebCore.h>
#include <iostream>
#include "time.h"
#include "ui.h"





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
	
	ui* userInterface;
	//Settings* linuxAPI;
};

#endif





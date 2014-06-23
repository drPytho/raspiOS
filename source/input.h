#ifndef INPUT
#define INPUT

#include <SDL2/SDL.h>

#define NUM_KEYCODES 256

class Input
{
public:
	Input();
	~Input();

	void updateInput();

	virtual void actionKeyDown(SDL_Keysym& sym)=0;
	virtual void actionKeyUp(SDL_Keysym& sym)=0;

	bool isCloseRequested()const{return closeRequested;}

private:
	SDL_Event* event;
	bool closeRequested;
	bool lastKeys[NUM_KEYCODES];
	bool currentKeys[NUM_KEYCODES];
};

#endif
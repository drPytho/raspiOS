#ifndef INPUT
#define INPUT

#include <SDL2/SDL.h>

#define NUM_KEYCODES 256

class Input
{
public:
	Input();
	~Input();

	void update();


	bool getKey(unsigned char key);
	bool getKeyDown(unsigned char key);
	bool getKeyUp(unsigned char key);

	inline bool isCloseRequested(){return closeRequested;}

private:
	char getChar(Uint16 unicode){

	}

	SDL_Event* event;
	bool closeRequested;
	bool lastKeys[NUM_KEYCODES];
	bool currentKeys[NUM_KEYCODES];
};

#endif
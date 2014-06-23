#include "input.h"

Input::Input()
{

}

Input::~Input()
{

}

void Input::updateInput()
{
	while(SDL_PollEvent(event))
	{
		switch(event->type)
		{
			case SDL_KEYDOWN:
				actionKeyDown(event->key.keysym);
				break;
			case SDL_KEYUP:
				actionKeyUp(event->key.keysym);
				break;
			case SDL_QUIT:
				closeRequested = true;
				break;
		}
	}
}



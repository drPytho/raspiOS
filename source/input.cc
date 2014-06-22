#include "input.h"

Input::Input()
{

}

Input::update()
{
	while(SDL_PollEvent(event))
	{
		if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
		{
			getChar();
		}

		if(event->type == SDL_QUIT)
			closeRequested = true;
	}
}



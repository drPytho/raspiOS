#include "pios.h"

Pios::Pios():
	window(NULL),
	screen(NULL),
	isRunning(0),
	lastTime(Time::getTime()),
	unprocessedTime(0),
	render(false),
	startTime(0),
	passedTime(0),
	frames(0),
	frameCounter(0)
{


}

Pios::~Pios()
{
	//Destroy window 
	SDL_DestroyWindow( window ); 

	//Quit SDL subsystems 
	SDL_Quit();
}

int Pios::run()
{
	isRunning = true;
	while(isRunning)
	{
		render = false;
		
		startTime = Time::getTime();
		passedTime = startTime - lastTime;
		lastTime = startTime;

		
		
		unprocessedTime += passedTime / (double)Time::SECOND;
		frameCounter += passedTime;
		while(unprocessedTime > FRAME_TIME)
		{
			render = true;
			unprocessedTime -= FRAME_TIME;
			
			
			//Input & Update here
			Input();



			if(frameCounter >= Time::SECOND)
			{
				std::cout << frames << " fps" << std::endl;
				frames = 0;
				frameCounter = 0;
			}
		}
		if(render)
		{
			//Render here
			Render();
			frames++;
		}
		else
			SDL_Delay(1);
	}

	return 0;
}

void Pios::Render()
{
	//Fill the surface white 
	SDL_FillRect(this->screen, NULL, SDL_MapRGB(this->screen->format, 0xFF, 0xFF, 0xFF)); 

	//Update the surface 
	SDL_UpdateWindowSurface(this->window); 
}

int Pios::halt()
{
	return 0;
}

void Pios::Input()
{
	updateInput();
	isRunning = !isCloseRequested();
}

void Pios::Update()
{

}

void actionKeyDown(SDL_Keysym& sym)
{

}

void actionKeyUp(SDL_Keysym& sym)
{

}

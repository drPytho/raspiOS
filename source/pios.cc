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
	//Init SDL with everything
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL failed to initialize. Error - " << SDL_GetError() << std::endl;
		exit(-1);
	}

	//Fullscreen, Window is vissable, Window has input focus
	this->window = SDL_CreateWindow("PIOS - V 0.0.1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, /*SDL_WINDOW_FULLSCREEN_DESKTOP |*/ SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_GRABBED);
	if (this->window == NULL)
	{
		std::cout << "SDL failed to create a window with SDL_Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	//Get the surface to draw on 
	this->screen = SDL_GetWindowSurface(this->window);
	if(this->screen == NULL)
	{
		std::cout << "SDL failed to return window surface with SDL_Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}


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



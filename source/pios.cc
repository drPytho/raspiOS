#include "pios.h"

Pios::Pios():
	m_isRunning(0),
	lastTime(0),
	unprocessedTime(0),
	render(false),
	startTime(0),
	passedTime(0),
	frames(0),
	frameCounter(0)
{
	//Create a new window here
	window = new Window(640, 480, "RaspiOS, V0.0.2 ALFA");
	window->SetFullScreen(1);
	window->GetInput().SetCursor(0);
}

Pios::~Pios()
{
	delete window;
}

void Pios::run()
{
	if(m_isRunning)
	{
		return;
	}

	m_isRunning = true;
	lastTime = Time::getTime();

	while(m_isRunning)
	{

		render = false;
		
		startTime = Time::getTime();
		passedTime = startTime - lastTime;
		lastTime = startTime;
		
		unprocessedTime += passedTime;
		frameCounter += passedTime;

		if(frameCounter >= 1.0)
		{
			//The framecounter code here is a temporary, basic profiling tool.
			//When proper profiling tools are implemented, this should probably be removed.

			//printf("%i\n",frames);
			std::cout << frames << " fps" << std::endl;
			frames = 0;
			frameCounter = 0;
		}

		while(unprocessedTime > FRAME_TIME)
		{
			//Input & Update here
			Update();
			Input();

			render = true;
			unprocessedTime -= FRAME_TIME;
		}
		if(render)
		{
			Render();
			frames++;
		}
		else
			SDL_Delay(1);
	}
}

void Pios::Render()
{
	//Render code here

	window->SwapBuffers();
}

void Pios::Input()
{

	m_isRunning = !window->IsCloseRequested();
	if(window->GetInput().GetKey(Input::KEY_A))
	{
		m_isRunning = false;
	}
}

void Pios::Update()
{
	window->Update();
}








	
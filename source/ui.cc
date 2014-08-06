#include "ui.h"

#define FRAME_CAP 5000
#define FRAME_TIME 1.0/FRAME_CAP

ui::ui(const std::string& title, int width, int height, bool fullscreen, const std::string& url):
	m_width(width),
	m_height(height),
	m_graphicsOn(true),
	m_url(url),
	m_title(title),
	m_window(nullptr),
	m_webView(nullptr),
	m_webCore(nullptr)
{
	
	m_window = new Window(m_width, m_height, m_title);
	m_window->SetFullScreen(fullscreen);
	m_window->GetInput().SetCursor(0);

	m_webCore = WebCore::Initialize(WebConfig());
	m_webView = m_webCore->CreateWebView(m_width, m_height);
	m_webView->LoadURL(WebURL(WSLit(m_url.c_str())));

	while(m_webView->IsLoading())
		m_webCore->Update();

	SDL_Delay(100);
	m_webCore->Update();
}

ui::~ui()
{

}

void ui::start()
{
	if(m_isRunning)
		return;
	
	m_isRunning = true;
	double lastTime = Time::GetTime();
	bool timeToRender = false;
	double startTime;
	double passedTime;
	double unprocessedTime = 0;
	int frameCounter = 0;
	int frames = 0; 

	while(m_isRunning)
	{

		timeToRender = false;
		
		startTime = Time::GetTime();
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
			update();
			input();

			timeToRender = true;
			unprocessedTime -= FRAME_TIME;
		}
		if(timeToRender && m_graphicsOn)
		{
			render();
			frames++;
		}
		else
			SDL_Delay(1);
	}
}

void ui::stop()
{
	if(m_isRunning == false)
		return;
	m_isRunning = false;
}

void ui::update()
{

	m_webCore->Update();
	m_window->Update();
}

void ui::render()
{
	m_window->ClearDisplay();

	//Draw here

	m_window->RenderToDisplay();
}

void ui::input()
{
	m_isRunning = !m_window->IsCloseRequested();
	m_isRunning = m_window->GetInput().GetKeyDown(KEY_A);
}


void ui::GetSSurf(SDL_Texture* texture)
{
	BitmapSurface* bitSurf = static_cast<BitmapSurface*>(m_webView->surface());

	if(bitSurf->is_dirty())
	{

		unsigned char* colorBuffer = NULL;
		int pitch;
		if (SDL_LockTexture(texture, NULL, (void**)&colorBuffer, &pitch) < 0)
		{
			//Misslyckades med LockTexture
			std::cout << "You failed to lock texture \n" << SDL_GetError() << "\n"; 
			return;
		}
		bitSurf->CopyTo(colorBuffer, pitch, 4, false, false);
		SDL_UnlockTexture(texture);
	}
	return/* :) */;
}

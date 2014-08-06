#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

#include <time.h>


#define WIDTH 640
#define HEIGHT 480

using namespace Awesomium;



#include <sys/time.h>
static const long NANOSECONDS_PER_SECOND = 1000000000L;



double GetTime()
{
	timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
	return (double)(((long) ts.tv_sec * NANOSECONDS_PER_SECOND) + ts.tv_nsec)/((double)(NANOSECONDS_PER_SECOND));
}

void GetSSurf(WebView* wv, SDL_Texture* texture)
{
	BitmapSurface* bitSurf = static_cast<BitmapSurface*>(wv->surface());

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

int main(int argc, char const *argv[])
{
	// SETUP

	std::cout << "SETUP" << std::endl;
	SDL_Window *m_window;
	SDL_Renderer *m_screen;
	std::string title = "Test window";
	std::string m_url = "http://www.google.se";

	//Init SDL with everything
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL failed to initialize. Error - " << SDL_GetError() << std::endl;
		exit(-1);
	}

	//Fullscreen, Window is vissable, Window has input focus
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_GRABBED);
	if (m_window == NULL)
	{
		std::cout << "SDL failed to create a window with SDL_Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		exit(-1);
	}

	//Get the surface to draw on 
	m_screen = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if(m_screen == NULL)
	{
		std::cout << "SDL failed to return window surface with SDL_Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		exit(-1);
	}

	SDL_RendererInfo info;
	SDL_GetRendererInfo(m_screen, &info);
	if(info.flags & SDL_RENDERER_SOFTWARE) {
		printf("WARNING: Using software renderer due to hardware fallback. Performance will suffer.\n");
	}
	if(!(info.flags & SDL_RENDERER_TARGETTEXTURE)) {
		printf("ERROR: Renderer does not support render-to-texture. Game will not run.");
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		exit(-1);
	}

	SDL_RenderSetLogicalSize(m_screen, WIDTH, HEIGHT);

	SDL_SetRenderDrawColor(m_screen, 0, 0, 0, 0);


	WebCore *m_webCore = WebCore::Initialize(WebConfig());

	WebView *m_webView = m_webCore->CreateWebView(WIDTH, HEIGHT);

	m_webView->LoadURL(WebURL(WSLit(m_url.c_str())));

	while(m_webView->IsLoading())
	{
		m_webCore->Update();
	}

	SDL_Delay(200);
	m_webCore->Update();

	//Create the texture 

	std::cout << "CREATE TEXTURE" << std::endl;

	SDL_Texture *texture = SDL_CreateTexture(m_screen, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

	std::cout << "RUNNING TEST FUNCTION" << std::endl;

	double startTime = GetTime();
	GetSSurf(m_webView, texture);
	std::cout << "Function timed in at " << GetTime() - startTime << "time units\n";

	//RUNNING

	std::cout << "RUNNING" << std::endl;


	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}

		SDL_RenderClear(m_screen);
		SDL_RenderCopy(m_screen, texture, NULL, NULL);
		SDL_RenderPresent( m_screen );
		SDL_Delay(10);
	}



	//CLEAN UP
	std::cout << "CLEAN UP" << std::endl;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(m_screen);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

	return 0;
}
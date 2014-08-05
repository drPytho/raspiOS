#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>
#include <SDL2/SDL.h>
#include <string>
#include <iostream>


#define WIDTH 640
#define HEIGHT 480

using namespace Awesomium;

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
	bitSurf->SaveToJPEG(WSLit("image.png"));

	return;
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
	m_screen = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if(m_screen == NULL)
	{
		std::cout << "SDL failed to return window surface with SDL_Error: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		exit(-1);
	}


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


	GetSSurf(m_webView, texture);


	//RUNNING

	std::cout << "RUNNING" << std::endl;

	SDL_SetRenderTarget(m_screen, NULL);
	SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
	SDL_RenderCopy(m_screen, texture, NULL, NULL);

	while (1) {
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}

		
	}



	//CLEAN UP
	std::cout << "CLEAN UP" << std::endl;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(m_screen);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

	return 0;
}
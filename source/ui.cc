#include "ui.h"

ui::ui(Window* window, const std::string& url):
	m_width(0),
	m_height(0),
	m_url(url),
	m_window(window),
	m_webView(NULL),
	m_webCore(NULL)
{
	
	m_webCore = WebCore::Initialize(WebConfig());

	

	m_webView = m_webCore->CreateWebView(m_width, m_height);

	m_webView->LoadURL(WebURL(WSLit(m_url.c_str())));

	while(m_webView->IsLoading())
	{
		m_webCore->Update();
	}

	SDL_Delay(200);
	m_webCore->Update();

	
}

ui::~ui()
{

}

SDL_Surface* ui::GetSSurf(WebView* wv, int width, int height)
{
	Uint32 RMASK, GMASK, BMASK, AMASK;

	RMASK = 0xFF000000;
	GMASK = 0x00FF0000;
	BMASK = 0x0000FF00;
	AMASK = 0x000000FF;

	BitmapSurface* bitSurf = static_cast<BitmapSurface*>(wv->surface());
	
	unsigned char* colorBuffer = NULL;
	bitSurf->CopyTo(colorBuffer, width * 4, 4, true, false);

	if(colorBuffer == NULL)
	{
		//YOu fucked up
	}

	SDL_Surface* tempSurf = NULL;

	tempSurf = SDL_CreateRGBSurfaceFrom(colorBuffer, width, height, 32, width * 4, RMASK, GMASK, BMASK, AMASK);
	
	delete[] colorBuffer;

	if(tempSurf == NULL)
	{
		//You fucked up
	}

	return tempSurf;
}

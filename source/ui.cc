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

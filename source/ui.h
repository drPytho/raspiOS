#ifndef UI
#define UI

#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>
#include <SDL2/SDL.h>
#include "window.h"
#include <string>

using namespace Awesomium;

class Window;

class ui
{
public:
	ui( Window* window, const std::string& url);
	~ui();

	static SDL_Surface* GetSSurf(WebView* wv, int width, int height);
protected:
	

private:
	//Window size
	int m_width;
	int m_height;

	std::string m_url;

	Window* m_window;
	
	WebCore* m_webCore;
	WebView* m_webView;

};

#endif
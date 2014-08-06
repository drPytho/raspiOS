#ifndef UI
#define UI

#include <Awesomium/WebCore.h>
#include <Awesomium/BitmapSurface.h>
#include <Awesomium/STLHelpers.h>
#include <SDL2/SDL.h>
#include "window.h"
#include <string>
#include "time.h"
#include "input.h"





using namespace Awesomium;

class ui
{
public:
	ui( const std::string& title, int width, int height, bool fullscreen, const std::string& url);
	~ui();

	void start();
	void stop();

	void Graphics(bool state){ m_graphicsOn = state; }

	inline const Input& GetInput() const { return m_window->GetInput(); }
	inline Window* getWindow(){ return m_window; }

protected:
private:
	void GetSSurf(SDL_Texture* texture);

	void update();
	void render();
	void input();

	bool m_graphicsOn;

	//Window size
	int m_width;
	int m_height;

	std::string m_url;
	std::string m_title;

	Window* m_window;
	
	WebCore* m_webCore;
	WebView* m_webView;

	//Cap
	bool m_isRunning;
	

};

#endif
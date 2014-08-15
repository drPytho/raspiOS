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
#include "LPI.h"





using namespace Awesomium;

class ui
{
public:
	ui( const std::string& title, int width, int height, bool fullscreen, const std::string& url);
	~ui();

	void start();
	void stop();

	// If the program is in the main focus or not and base the 
	// amount of actions the program should take
	void backgroundMood(bool state){ m_backgroundMood = state; }

	// 
	inline const Input& GetInput() const { return m_window->GetInput(); }
	inline Window* getWindow() { return m_window; }

protected:
private:
	void GetSSurf(SDL_Texture* texture);

	void update();
	void render();
	void input();


	void initHTML(std::string paths);
	void updateHTML(std::string paths);
	JSObject* const createHTMLInfoObject(const std::string& searchPaths) const;


	bool m_backgroundMood;

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
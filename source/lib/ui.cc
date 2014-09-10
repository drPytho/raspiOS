#include "ui.h"

#define FRAME_CAP 5000
#define FRAME_TIME 1.0/FRAME_CAP

ui::ui(const std::string& title, int width, int height, bool fullscreen, const std::string& url):
	m_width(width),
	m_height(height),
	m_backgroundMood(true),
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
	//Stop awesomium

	//Stop SDL, (AKA) m_window
}


/**
* @description
*	  Should clean up everything that can throw an error
* @post
*    You should not try to run the ui after this
* @param [0, n-1] paramName
*    None
* @return
*    bool - true on success
* @throw
*    None so far
*/
bool ui::terminate()
{

}


/**
 * @description
 *	  Starts the application clock, goes through and updates everything.
 * @pre
 *    For the constructor to have run
 * @post
 *    Well there has got to be some clean up
 * @param [0, n-1] paramName
 *    None
 * @return
 *    Void
 * @throw
 *    None
 */

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
			// The framecounter code here is a temporary, basic profiling tool.
			// When proper profiling tools are implemented, this should probably be removed.

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
		if(timeToRender && m_backgroundMood)
		{
			render();
			frames++;
		}
		else
			SDL_Delay(1);
	}
}

/**
 * @description
 *	  Stops the application clock. Does not clean up the 
 *    mess so it can continue from it's current state
 * @pre
 *    None, Won't do any good if the start function hasn't been caled. 
 * @post
 *    Possible to restart
 * @param [0, n-1] paramName
 *    None
 * @return
 *    Void
 * @throw
 *    None
 */

void ui::stop()
{
	if(m_isRunning == false)
		return;
	m_isRunning = false;
}

/**
 * @description
 *	  Runns through and updates everything needed to be updated
 * @pre
 *    None, Constructor
 * @post
 *    
 * @param [0, n-1] paramName
 *    None
 * @return
 *    Void
 * @throw
 *    None
 */

void ui::update()
{

	m_webCore->Update();
	m_window->Update();
}

/**
 * @description
 *	  Clears the display, renders to the renderer and outputs to the screen.
 * @pre
 *    None, Constructor
 * @post
 *    
 * @param [0, n-1] paramName
 *    None
 * @return
 *    Void
 * @throw
 *    None
 */

void ui::render()
{
	m_window->ClearDisplay();

	//Draw here

	m_window->RenderToDisplay();
}

/**
 * @description
 *	  Updates the input, checks if close requested. Then misc input
 * @pre
 *    None, Constructor
 * @post
 *    
 * @param [0, n-1] paramName
 *    None
 * @return
 *    Void
 * @throw
 *    None
 */

void ui::input()
{
	m_window->UpdateInput();
	m_isRunning = !m_window->IsCloseRequested();
	m_isRunning = m_window->GetInput().GetKeyDown(Input::KEY_A);

}

/**
 * @description
 *	  Creates an SDL_Texture from the Awesomium WebView's bitmap
 * @pre
 *    None, Constructor
 * @post
 *    
 * @param [0, n-1] paramName
 *    None
 * @return
 *    Void
 * @throw
 *    Miss on locking texture
 *
 * @note
 *    Nees to check for possible memmory leaks with reapeted use.
 */

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

/**
 * @description
 *	  Creates the json object to load the javascript with information
 * @pre
 *    None
 * @post
 *    Need to clean up the jsObject
 * @param [0, n-1] paramName
 *    None
 * @return
 *    A JSObject pointer 
 * @throw
 *    Nothing
 *
 * @note
 *    Nees to check for possible memmory leaks with reapeted use.
 */


JSObject* const ui::createHTMLInfoObject(const std::string searchPaths[]) const
{
    std::vector<std::string> files = LPI::getFilesInFolder(searchPaths);

    for(std::string file : files)
    {
        switch(LPI::getFileType(LPI::getExtention(file)))
        {

            case LPI::D_VIDEO:
                JSON_Helper::JSON_MOVIE *m = new JSON_Helper::JSON_MOVIE(LPI::getFileName(file), file, );
                break;
        }
    }
}




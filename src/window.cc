#include "window.h"

Window::Window(int width, int height, const std::string& title)
:	m_width(width),
	m_height(height),
	m_title(title),
	m_input(this),
	m_isCloseRequested(false)
{

	
	//Init SDL with everything
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL failed to initialize. Error - " << SDL_GetError() << std::endl;
		exit(-1);
	}

	//Fullscreen, Window is vissable, Window has input focus
	m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_INPUT_GRABBED);
	if (m_window == nullptr)
	{
		std::cout << "SDL failed to create a window with SDL_Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	//Get the surface to draw on 
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
	if(m_renderer == nullptr)
	{
		std::cout << "SDL failed to return window surface with SDL_Error: " << SDL_GetError() << std::endl;
		exit(-1);
	}

	SDL_RendererInfo info;
	SDL_GetRendererInfo(m_renderer, &info);
	if(info.flags & SDL_RENDERER_SOFTWARE) {
		printf("WARNING: Using software renderer due to hardware fallback. Performance will suffer.\n");
	}
	if(!(info.flags & SDL_RENDERER_TARGETTEXTURE)) {
		printf("ERROR: Renderer does not support render-to-texture. Game will not run.");
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		exit(-1);
	}

	SDL_RenderSetLogicalSize(m_renderer, m_width, m_height);

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);

}

Window::~Window()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Window::Update()
{

}

void Window::UpdateInput()
{
	//Substetute with memset 0
	for(int i = 0; i < Input::NUM_MOUSEBUTTONS; i++)
	{
		m_input.SetMouseDown(i, false);
		m_input.SetMouseUp(i, false);
	}

	for(int i = 0; i < Input::NUM_KEYS; i++)
	{
		m_input.SetKeyDown(i, false);
		m_input.SetKeyUp(i, false);
	}

	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
		if(e.type == SDL_QUIT)
		{
			m_isCloseRequested = true;
		}

		if(e.type == SDL_MOUSEMOTION)
		{
			m_input.SetMouseX(e.motion.x);
			m_input.SetMouseY(e.motion.y);
		}

		if(e.type == SDL_KEYDOWN)
		{
			int value = e.key.keysym.scancode;

			m_input.SetKey(value, true);
			m_input.SetKeyDown(value, true);
		}
		if(e.type == SDL_KEYUP)
		{
			int value = e.key.keysym.scancode;

			m_input.SetKey(value, false);
			m_input.SetKeyUp(value, true);
		}
		if(e.type == SDL_MOUSEBUTTONDOWN)
		{
			int value = e.button.button;

			m_input.SetMouse(value, true);
			m_input.SetMouseDown(value, true);
		}
		if(e.type == SDL_MOUSEBUTTONUP)
		{
			int value = e.button.button;

			m_input.SetMouse(value, false);
			m_input.SetMouseUp(value, true);
		}
	}
}

void Window::RenderToDisplay()
{
	SDL_RenderPresent( m_renderer );
}

void Window::ClearDisplay()
{

}

void Window::SetFullScreen(bool value)
{
	int mode = 0;
	if(value)
		mode = SDL_WINDOW_FULLSCREEN;

	SDL_SetWindowFullscreen(m_window, mode);
}

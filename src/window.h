#ifndef WINDOW
#define WINDOW

#include <SDL2/SDL.h>
#include <string>
#include "input.h"
#include <iostream>

class Window
{
public:
	Window(int width, int height, const std::string& title);
	virtual ~Window();

	void Update();
	void UpdateInput();
	void RenderToDisplay();
	void ClearDisplay();

	inline bool IsCloseRequested() const { return m_isCloseRequested; }
	inline int GetWidth() const { return m_width; }
	inline int GetHeight() const { return m_height; }
	inline float GetAspect() const { return (float)m_width/(float)m_height; }
	inline const std::string& GetTitle() const { return m_title; }
	inline Vector2f GetCenter() const { return Vector2f((float)m_width/2.0f, (float)m_height/2.0f); }
	inline SDL_Window* GetSDLWindow() { return m_window; }
	inline SDL_Renderer* GetSDLWindowSurface(){ return m_renderer; }
	inline const Input& GetInput() const { return m_input; }

	void SetFullScreen(bool value);
protected:
private:


	
	

	int m_width;
	int m_height;
	std::string m_title;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	Input m_input;
	bool m_isCloseRequested;

	Window(const Window& other) : m_input(this) {}
	void operator=(const Window& other) {}

};



#endif
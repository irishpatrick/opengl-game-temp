#pragma once

#include <SDL2/SDL.h>

class Context
{
public:
    Context();
    ~Context();

	void clear();
	void flip();

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_GLContext m_glctx;
};

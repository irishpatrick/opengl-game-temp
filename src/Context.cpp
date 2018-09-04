#include "Context.hpp"
#include <iostream>
#include <GL/glew.h>

Context::Context()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << SDL_GetError() << std::endl;
        std::exit(1);
    }

    m_window = SDL_CreateWindow(
        "title",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1024,
        768,
        SDL_WINDOW_OPENGL
    );

    if (m_window == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        std::exit(1);
    }

    // gl stuff
    
	// core profile
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    // version 3.2
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    // double buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	// vsync
	SDL_GL_SetSwapInterval(1);

    m_glctx = SDL_GL_CreateContext(m_window);
    if (m_glctx == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        std::exit(1);
    }

    // glew stuff
	// the guards are needed for apple
	#ifndef __APPLE__
    glewExperimental = GL_TRUE;
    glewInit();
	#endif
}

Context::~Context()
{
	SDL_GL_DeleteContext(m_glctx);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Context::clear()
{
	glClearColor(0.0f, 0.3f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Context::flip()
{
	SDL_GL_SwapWindow(m_window);
}

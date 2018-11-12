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

    SDL_DisplayMode current;
    SDL_GetCurrentDisplayMode(0, &current);
    int w = current.w;
    int h = current.h;

    m_window = SDL_CreateWindow(
        "title",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,
        720,
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
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
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

    projection = glm::perspective(
        glm::radians(80.0f),
        16.0f/9.0f,
        0.1f,
        100.0f
    );

    // glew stuff
	// the guards are needed for apple
	#ifndef __APPLE__
    glewExperimental = GL_TRUE;
    glewInit();
    if (glewIsSupported("GL_VERSION_3_3"))
    {
        std::cout << "ready for 3.3" << std::endl;
    }
    else
    {
        std::cout << "version not supported" << std::endl;
    }
	#endif
}

Context::~Context()
{
	SDL_GL_DeleteContext(m_glctx);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

glm::mat4& Context::getProjectionMatrix()
{
    return projection;
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

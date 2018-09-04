#include "Context.hpp"
#include <iostream>
#include <glew.h>

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
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_glctx = SDL_GL_CreateContext(m_window);
    if (m_glctx == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        std::exit(1);
    }

    // glew stuff
    glewExperimental = GL_TRUE;
    glewInit();
}

Context::~Context()
{

}

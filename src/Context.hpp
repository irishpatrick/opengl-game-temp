#pragma once

#include <SDL2/SDL.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Context
{
public:
    Context();
    ~Context();

	void clear();
	void flip();

    glm::mat4& getProjectionMatrix();

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_GLContext m_glctx;
    glm::mat4 projection;
};

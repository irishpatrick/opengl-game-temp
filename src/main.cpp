#include <iostream>
#include <cstdint>

#include "Context.hpp"
#include "Model.hpp"
#include "TestTriangle.hpp"

Context ctx;
SDL_Event e;
bool quit = false;

Model m;
TestTriangle t;

void init()
{
	m.init();
	t.init();
}

void render()
{
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		const uint8_t* keys = SDL_GetKeyboardState(nullptr);

		if (keys[SDL_SCANCODE_ESCAPE])
		{
			quit = true;
		}

		ctx.clear();
		m.draw();
		t.draw();
		ctx.flip();
	}
}

int main(int argc, char* argv[])
{
    std::cout << "hello world" << std::endl;
	init();
	render();
    return 0;
}

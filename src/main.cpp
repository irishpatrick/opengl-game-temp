#include <iostream>

#include "Context.hpp"

Context ctx;
SDL_Event e;
bool quit = false;

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

		ctx.clear();
		ctx.flip();
	}
}

int main(int argc, char* argv[])
{
    std::cout << "hello world" << std::endl;
	render();
    return 0;
}

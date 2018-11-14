#include <iostream>
#include <cstdint>
#include <experimental/filesystem>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/ext.hpp>

#include "Context.hpp"
#include "Model.hpp"
#include "TestTriangle.hpp"
#include "Shader.hpp"

namespace fs = std::experimental::filesystem;

Context ctx;
SDL_Event e;
bool quit = false;

glm::mat4 view;

Model m;
TestTriangle t;
Shader shader;

void init()
{
	//view = glm::mat4(1.0f);
	view = glm::lookAt(
		glm::vec3(4,3,3),
		glm::vec3(0,0,0),
		glm::vec3(0,1,0)
	);
	m.init();
	t.init();
	t.position.x = 10.0f;
	//t.position.y = 10.0f;
	std::cout << "init shader" << std::endl;
	shader.loadShader(fs::path(fs::current_path() / "assets" / "vertex.glsl").generic_string(), GL_VERTEX_SHADER);
	shader.loadShader(fs::path(fs::current_path() / "assets" / "fragment.glsl").generic_string(), GL_FRAGMENT_SHADER);
	shader.linkProgram();
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

		t.update();

		ctx.clear();
		shader.use();
		glm::mat4 mp = t.getMatrix();
		shader.setMatrix4("mvp", t.getMatrix());
		std::cout << glm::to_string(t.getMatrix()) << std::endl;
		//m.draw();
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

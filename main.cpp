#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>

//void process_input(SDL_Window *window){
	// set draw color
	//SDL_SetRenderDrawColor(renderer, r, g, b, a);

//}

void do_basic_draw() {
	GLfloat points[] = {
		-0.5,  0.5,
		 0.0,  0.0,
		 0.5, -0.5
	};
	GLuint indices[] {
		0,1,2
	};
	std::cout << "Attemtpting to draw poitns" << std::endl;
	
	// Bind VBO and EBO => Find out what these are
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
	//glDrawArrays(GL_POINTS, 0, sizeof(points)/sizeof(GLfloat) / 2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Draw
	glDrawElements(GL_POINTS, 3, GL_UNSIGNED_INT,0);

}

int main() {
    std::cout << "Starting program\n";

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << "\n";
        return 1;
    }

    // Request OpenGL 3.3 core
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    SDL_Window* window = SDL_CreateWindow(
        "SDL + OpenGL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_OPENGL
    );

    SDL_GLContext context = SDL_GL_CreateContext(window);

    // Init GLEW AFTER context creation
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW init failed\n";
        return 1;
    }

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        glClearColor(0.1f, 0.1f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw stuff here (later 😉)
		do_basic_draw();
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

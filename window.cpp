//#include <GL/glew.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

struct gl_window {
    int height;
    int width;
    const char title[12];

    GLFWwindow* create(int width, int height){
        GLFWwindow* window = glfwCreateWindow( width, height,title, NULL , NULL);
        return window;
    }

};

int main() {

    std::cout << "Starting program"<< std::endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialising glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    return 0;
}
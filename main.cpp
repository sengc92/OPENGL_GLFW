//glew, run static
#define GLEW_STATIC
#include <GL/glew.h>
//glfw
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

//window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

int main(){

    cout << "staring GLFW context!" << endl;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // no legacy code
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); for mac os

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);

    if(window == nullptr){
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate(); //terminate opengl?
        return -1;
    }

    glfwMakeContextCurrent(window); //current state at the window?

    //set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        cout << "Failed to initialize GLEW" << endl;
        return -1;
    }

    // Define viewport dimensions
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0,0,width,height);

    //game loop, makes the program keeps drawing
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents(); //check for key inputs and calls correspond funcs
        glfwSwapBuffers(window); //swap the color buffer that has been used to draw during this iteration and show it to the screen
    }

    //double buffer, when app draws in a single buffer the resulting image might display flickering issues. Because result images are not displayed
    //at an instant to the user, but in a step by step manner resulting artifacts. double buffer for rendering.

    //delete allocated resources
    glfwTerminate();

    return 0;
}
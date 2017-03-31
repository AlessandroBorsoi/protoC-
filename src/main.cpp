#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <Game.h>

const GLuint WIDTH = 800;
const GLuint HEIGHT = 600;
Game game;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {
    if (!glfwInit()) {
        std::cout << "failed to initialize GLFW.\n";
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "ProtoC++", nullptr, nullptr);
    if (window == NULL) {
        std::cout << "Failed to create the GLFW window\n";
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (gl3wInit()) {
        std::cout << "failed to initialize OpenGL.\n";
        return -1;
    }
    std::cout << "OpenGL " << glGetString(GL_VERSION) << ", GLSL " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";
    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(window, (videoMode->width - WIDTH) / 2, (videoMode->height - HEIGHT) / 2);
    glfwSetKeyCallback(window, keyCallback);
    glfwShowWindow(window);
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    game.init();

    while (!glfwWindowShouldClose(window)) {
        game.update(0);
        game.render(0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    game.clear();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

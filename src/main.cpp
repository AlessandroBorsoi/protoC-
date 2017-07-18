#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <Game.h>

using namespace std;

Game game;

void keyCallback(GLFWwindow * window, int key, int scancode, int action, int mods);

int main() {
    if (!glfwInit()) {
        cout << "failed to initialize GLFW." << endl;
        return EXIT_FAILURE;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    GLFWwindow * window = glfwCreateWindow(game.WIDTH, game.HEIGHT, "ProtoC++", nullptr, nullptr);
    if (window == nullptr) {
        cout << "Failed to create the GLFW window" << endl;
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    if (gl3wInit()) {
        cout << "failed to initialize OpenGL." << endl;
        return EXIT_FAILURE;
    }
    cout << "OpenGL " << glGetString(GL_VERSION) << ", GLSL " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
    const GLFWvidmode * videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    glfwSetWindowPos(window, (videoMode->width - game.WIDTH) / 2, (videoMode->height - game.HEIGHT) / 2);
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

void keyCallback(GLFWwindow * window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

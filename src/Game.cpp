#include <Game.h>
#include <GL/gl3w.h>
#include <ResourceManager.h>

Game::Game() {}

Game::~Game() {}

void Game::init() {
    ResourceManager::init();
}

void Game::update(float dt) {

}

void Game::render(float alpha) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Game::clear() {
    ResourceManager::clear();
}

#include <Planet.h>
#include <ResourceManager.h>
#include <glm/detail/type_mat2x2.hpp>
#include <glm/gtc/matrix_transform.inl>

Planet::Planet() {
    this->shader = ResourceManager::getShader("irregular");
}

Planet::~Planet() {}

void Planet::update(float dt) {}

void Planet::render(float alpha) {
    this->shader->use();
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(800), static_cast<GLfloat>(600), 0.0f, -1.0f, 1.0f);
    this->shader->setMatrix4("projection", projection);
}

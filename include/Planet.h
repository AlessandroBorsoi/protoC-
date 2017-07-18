#ifndef PROTOC_PLANET_H
#define PROTOC_PLANET_H

#include <glm/vec2.hpp>
#include "Shader.h"

class Planet {
private:
    Shader * shader;
    glm::vec2 position;
public:
    Planet();
    ~Planet();
    void update(float dt);
    void render(float alpha);
};

#endif //PROTOC_PLANET_H

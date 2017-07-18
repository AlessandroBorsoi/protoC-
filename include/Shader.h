#ifndef PROTOC_SHADER_H
#define PROTOC_SHADER_H

#include <GLFW/glfw3.h>
#include <string>
#include <glm/detail/type_mat.hpp>
#include <glm/gtc/type_ptr.inl>

using namespace std;

class Shader {
private:
    GLuint id;
    string name;
public:
    Shader(string name);
    ~Shader();
    void load();
    Shader & use();
    void setMatrix4(const GLchar * name, const glm::mat4 & matrix);
};

#endif //PROTOC_SHADER_H

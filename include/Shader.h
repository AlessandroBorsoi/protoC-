#ifndef PROTOC_SHADER_H
#define PROTOC_SHADER_H

#include <GLFW/glfw3.h>
#include <string>

using namespace std;

class Shader {
private:
    GLuint id;
    string name;
public:
    Shader(string name);
    ~Shader();
    void load();
};

#endif //PROTOC_SHADER_H

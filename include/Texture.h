#ifndef PROTOC_TEXTURE_H
#define PROTOC_TEXTURE_H

#include <string>
#include <GLFW/glfw3.h>

using namespace std;

class Texture {
private:
    GLuint id;
    string name;
    int width;
    int height;
    int rows;
    int columns;
public:
    Texture(string name, int rows = 0, int columns = 0);
    ~Texture();
    void load();
};

#endif //PROTOC_TEXTURE_H

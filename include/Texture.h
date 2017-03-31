#ifndef PROTOC_TEXTURE_H
#define PROTOC_TEXTURE_H

#include <string>

class Texture {
private:
    int id;
    std::string name;
    int width;
    int height;
    int rows;
    int columns;
public:
    Texture(std::string name, int width, int height, int rows = 0, int columns = 0);
    ~Texture();
};

#endif //PROTOC_TEXTURE_H

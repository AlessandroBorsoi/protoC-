#include <Texture.h>

Texture::Texture(std::string name, int width, int height, int rows, int columns) {
    Texture::name = name;
    Texture::width = width;
    Texture::height = height;
    Texture::rows = rows;
    Texture::columns = columns;
}

Texture::~Texture() {}

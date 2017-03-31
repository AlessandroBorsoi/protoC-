#include <GL/gl3w.h>
#include <Texture.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture::Texture(std::string name, int rows, int columns) {
    this->name = name;
    this->rows = rows;
    this->columns = columns;
}

Texture::~Texture() {}

void Texture::load() {
    int comp;
    string path = "../resources/texture/" + this->name + ".png";
    unsigned char* image = stbi_load(path.c_str(), &this->width, &this->height, &comp, STBI_rgb_alpha);
    if (image == nullptr) {
        cout << "Failed to load the texture " << this->name << "\n";
        throw string("Failed to load the texture");
    }
    cout << "Loading texture " << this->name << " in memory...\n";
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(image);
}

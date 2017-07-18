#ifndef PROTOC_RESOURCEMANAGER_H
#define PROTOC_RESOURCEMANAGER_H

#include <map>
#include <string>
#include <Texture.h>
#include "Shader.h"

using namespace std;

class ResourceManager {
private:
    ResourceManager();
    static map<string, Texture *> textures;
    static map<string, Shader *> shaders;
public:
    static void init();
    static void clear();
    static Shader * getShader(string name);
};

#endif //PROTOC_RESOURCEMANAGER_H

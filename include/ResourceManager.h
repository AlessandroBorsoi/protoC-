#ifndef PROTOC_RESOURCEMANAGER_H
#define PROTOC_RESOURCEMANAGER_H

#include <map>
#include <string>
#include <Texture.h>

using namespace std;

class ResourceManager {
private:
    ResourceManager();
    static map<string, Texture*> textures;
public:
    static void init();
    static void clear();
};

#endif //PROTOC_RESOURCEMANAGER_H

#include <map>
#include <string>
#include <ResourceManager.h>

using namespace std;

map<string, Texture*> ResourceManager::textures;

ResourceManager::ResourceManager() {}

void ResourceManager::init() {
    ResourceManager::textures.insert(pair<string, Texture*>("PlayerShip", new Texture("PlayerShip", 512, 512, 4, 4)));
    ResourceManager::textures.insert(pair<string, Texture*>("Stage1Layer1", new Texture("Stage1Layer1", 1024, 1024)));
}

void ResourceManager::clear() {
    for (auto & texture : ResourceManager::textures) {
        delete texture.second;
    }
}
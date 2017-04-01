#include <map>
#include <string>
#include <ResourceManager.h>

using namespace std;

map<string, Texture*> ResourceManager::textures;
map<string, Shader*> ResourceManager::shaders;

ResourceManager::ResourceManager() {}

void ResourceManager::init() {
    ResourceManager::textures.insert(pair<string, Texture*>("PlayerShip", new Texture("PlayerShip", 4, 4)));
    ResourceManager::textures.insert(pair<string, Texture*>("Stage1Layer1", new Texture("Stage1Layer1")));

    ResourceManager::shaders.insert(pair<string, Shader*>("regular", new Shader("regular")));
    ResourceManager::shaders.insert(pair<string, Shader*>("irregular", new Shader("irregular")));

    for (auto & texture : ResourceManager::textures)
        texture.second->load();
    for (auto & shader : ResourceManager::shaders)
        shader.second->load();
}

void ResourceManager::clear() {
    for (auto & texture : ResourceManager::textures)
        delete texture.second;
    for (auto & shader : ResourceManager::shaders)
        delete shader.second;
}
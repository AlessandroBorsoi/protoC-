#ifndef PROTOC_GAME_H
#define PROTOC_GAME_H

#include <GL/gl3w.h>

class Game {
public:
    const GLuint WIDTH = 800;
    const GLuint HEIGHT = 600;
    Game();
    ~Game();
    void init();
    void update(float dt);
    void render(float alpha);
    void clear();
};

#endif //PROTOC_GAME_H

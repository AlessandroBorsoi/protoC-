#ifndef PROTOC_GAME_H
#define PROTOC_GAME_H

class Game {
public:
    Game();
    ~Game();
    void init();
    void update(float dt);
    void render(float dt);
    void clear();
};

#endif //PROTOC_GAME_H

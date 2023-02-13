#pragma once
#include "CHARACTER.h"
#include "libOne.h"
class PLAYER :
    public CHARACTER
{
public:
    struct DATA {
        int image = 0;
        VECTOR2 pos{};
        VECTOR2 vec{};
        float moveSpeed = 0;
        float g = 0;
        float angle = 0;
        float size = 0;
    };

private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void init();
    void update();
    void move();
   void collision();
    void jump();
    void draw();
};


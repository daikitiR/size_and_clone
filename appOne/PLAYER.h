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
        bool flag = 0;
        int sizeMode = 0;
        int sound = 0;
    };
    float pustPlayerX = 0;
    float pustPlayerY = 0;
    //jump 
    bool JumpNow = 0;
    float  vy = -19, initvy = -20;
    //“–‚½‚è”»’è
    struct RECT {
        float x = 0, y = 0, w = 55, h = 96 - 7;
        float right = 0, left = 0, top = 0, bottom = 0;
        float sizecal = 1;
    };
    //sound
private:
    RECT p{};
    DATA Player{};
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void init();
    void update();
    void draw();
    void woodcol(VECTOR2* wpos);
private:
    void moveX();
    void moveY();
    void collisionX();
    void collisionY();
    void cloneSpawn();
    void sizeChange();
    void gravity();
 
};
;

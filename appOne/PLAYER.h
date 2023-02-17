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
        int sound = 0;
    };
    float pustPlayerX = 0;
    float pustPlayerY = 0;
   //jump 
    bool JumpNow = 0;
    float  vy = 0, initvy = -20;

    //sound
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void init();
    void update();
    void cloneSpawn();
    void setPlayerCOL();
    void moveX();
    void moveY();
    void collisionX();
    void collisionY();
    void gravity();
    void draw();
};


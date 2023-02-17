#pragma once
#include "CHARACTER.h"
#include "libOne.h"
class CLONE :
    public CHARACTER
{
 public:
    struct DATA {
        int cloneTotalNum = 4;
        int cloneNum = 5;
        int image = 0;
        float moveSpeed = 0;
        float g = 0;
        float angle = 0;
    };
    //jump 
    bool JumpNow = 0;
    float  vy = 0, initvy = -20;
private:
    DATA Clone;
    //単体データ
    struct TheCLONE {
        VECTOR2 pos{};
        VECTOR2 vec{1,1};
        float angle = 0;
        float size = 1;
        float pustCloneX = 0;
        float pustCloneY = 0;
    };
    TheCLONE* TheClone{};
public:
    CLONE(class GAME* game);
    ~CLONE();
    void create();
    void init();
    void update();
    void spawn(const VECTOR2& pos);
    void draw();
    void moveX(int i);
    void moveY(int i );
    void collisionX(int i);
    void collisionY(int i);
    void gravity(int i);
private:
    void kill(int i);
};




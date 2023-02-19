#pragma once
#include "CHARACTER.h"
#include "libOne.h"
class CLONE:
    public CHARACTER
{
 public:
    struct DATA {
        int cloneTotalNum = 4;
        int cloneNum = 5;
        int image = 0;
        float moveSpeed = 0;
        float angle = 0;
        int sound = 0;
    };
    //jump 
    DATA Clone;
    //単体データ
    struct TheCLONE {
        VECTOR2 pos{};
        VECTOR2 vec{ 1,1 };
        float angle = 0;
        float size = 1;
        float g = 10;
        bool JumpNow = 0;
        float  vy = 0, initvy = -20;
        float pustCloneX = 0;
        float pustCloneY = 0;
    };
    struct RECT {
        float x = 0, y = 0 , w = 55, h = 96-7;
        float right, left, top, bottom;
    };
    RECT p{};
    TheCLONE* TheClone{};
public:
    CLONE(class GAME* game);
    ~CLONE();
    void create();
    void init();
    void update();
    void spawn(float posx,float posy);
    void draw();
    void woodcol(int i,VECTOR2* wpos);

private:
    void moveX(int i);
    void moveY(int i );
    void collisionX(int i);
    void collisionY(int i);
    void gravity(int i);
    void kill(int i);
};
;



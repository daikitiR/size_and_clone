#pragma once
#include "CHARACTER.h"
#include "libOne.h"
class WOODBOX :
    public CHARACTER
{
public:
    struct DATA {
        int image = 0;
        VECTOR2 pos{};
        VECTOR2 vec{};
        float moveSpeed = 0;
        float g = 0;
        bool flag = 0;
    };
    float pustWoodBoxX = 0;
    float pustWoodBoxY = 0;
    //“–‚½‚è”»’è
    struct RECT {
        float x = 0, y = 0, w = 60, h = 60;
        float right = 0, left = 0, top = 0, bottom = 0;
    };
    //sound
private:
    DATA woodbox{};
    RECT woodBoxRect{};
public:
    WOODBOX(class GAME* game);
    ~WOODBOX();
    void create();
    void init();
    void update();
    void draw();
    void PlayercolMove(VECTOR2* pos, float size);
    void ClonecolMove(VECTOR2* pos, int i);
private:
    void moveX();
    void moveY();
    void collisionX();
    void gravity();
    void collisionY();
};



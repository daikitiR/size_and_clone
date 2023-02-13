#pragma once
#include "CHARACTER.h"
#include "libOne.h"
class BLOCK :
    public CHARACTER
{
public:
    struct DATA {
        int image = 0;
        VECTOR2 pos{};
        float angle = 0;
        float size = 0;
    };
private:
    DATA Block;
public:
    BLOCK(class GAME* game);
    ~BLOCK();
    void create();
    void init();
    void update(int i,int j);
    void draw(int i, int j);
};


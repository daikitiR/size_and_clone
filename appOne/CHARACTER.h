#pragma once
#include "GAME_OBJECT.h"
class CHARACTER :
    public GAME_OBJECT
{
public:
    CHARACTER(class GAME* game);
    virtual ~CHARACTER();
    virtual void create();
    virtual void init();
    virtual void update();
    virtual void draw();
};


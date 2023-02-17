#pragma once
#include "SCENE.h"
#include "libOne.h"
class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA
    {
        COLOR backColor = 0;
        VECTOR2 pos;
        static const int memorySize = 16;
        char str[memorySize]{};
    };
    struct IMAGES
    {
        static const int T_image_num = 1;
        struct Game_Clear_images {
            int image{};
            VECTOR2 pos;
            float angle = 0;
            float size = 1;
            float transmission = 0;
        };
        Game_Clear_images images[T_image_num]{};
    };
private:
    DATA Game_clear;
    IMAGES C_image;
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void draw();
    void create();
    void nextScene();

};
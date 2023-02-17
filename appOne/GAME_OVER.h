#pragma once
#include "SCENE.h"
#include "libOne.h"
class GAME_OVER :
    public SCENE
{
public:
    struct DATA
    {
        COLOR backColor = 0;
        COLOR textColor = 0;
        float textSize = 0;
        VECTOR2 pos;
        static const int memorySize = 16;
        char str[memorySize]{};
    };
    struct IMAGES
    {
        static const int T_image_num = 1;
        struct Game_Over_images {
            int image{};
            VECTOR2 pos;
            float angle = 0;
            float size = 1;
            float transmission = 0;
        };
        Game_Over_images images[T_image_num]{};
    };
private:
    DATA Game_over;
    IMAGES O_image;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void draw();
    void create();
    void nextScene();

};
#pragma once
#include "SCENE.h"
#include "libOne.h"
class TITLE :
    public SCENE
{
public:
    struct DATA
    {
        COLOR backColor = 0;
        COLOR textColor = 0;
        COLOR MenuTextColor = 0;
        COLOR MenuBarColor = 0;
        float alpha = 0;
        float added = 0;
        float textSize = 0;
        float menuSize = 0;
        int selection = 0;
        static const int memorySize = 20;
        static const int menunum = 4;
        struct MenuName
        {
            char str[memorySize]{};
            VECTOR2 pos;
        };
        MenuName menuname[menunum]{};
    };

    struct IMAGES
    {
        static const int T_image_num = 6;
        struct Titleimages {
            int image{};
            VECTOR2 pos;
            float angle = 0;
            float size = 1;
            float transmission = 0;
        };
        Titleimages images[T_image_num]{};
    };
private:
    DATA Title;
    IMAGES T_Images;
    void MenuBarDraw();
    void select(int *selection);
public:
    TITLE(class GAME* game);
    ~TITLE();
    void draw();
    void create();
    void update();
    void nextScene();
};


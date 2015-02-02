#pragma once
#include <cocos2d.h>

class TitleScene : cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TitleScene);
    
private:
    void gameStart();
};
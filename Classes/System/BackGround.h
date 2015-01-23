#pragma once
#include <cocos2d.h>

class BackGround : public cocos2d::Sprite {
public:
    BackGround(cocos2d::Size windowSize_, cocos2d::Layer &sceneLayer);
    ~BackGround();
    Sprite *backGround_f;
    Sprite *backGround_b;
    void Move(float speedRate);
    
private:
    cocos2d::Size windowSize;
};
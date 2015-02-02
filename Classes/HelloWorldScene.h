#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "TaskManager.h"
#include "BackGround.h"


class HelloWorld : public cocos2d::Layer
{
public:
    cocos2d::Size windowSize;
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    TaskManager *taskManager;
    BackGround *background;
    void update(float frame);
    void PlayerSet(cocos2d::Size windowSize);
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    cocos2d::Point startPoint, endPoint;
};

#endif // __HELLOWORLD_SCENE_H__

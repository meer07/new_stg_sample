#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Player.h"
#include "GameScene.h"
#include "TaskManager.h"

class HelloWorld : public cocos2d::Layer
{
public:
    Size windowSize;
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    void update(float frame);
    void PlayerSet(Size windowSize);
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchMoved(Touch *touch, Event *event);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    int nowStage = 1;
    GameScene *gameScene;
    Point startPoint, endPoint;
};

#endif // __HELLOWORLD_SCENE_H__

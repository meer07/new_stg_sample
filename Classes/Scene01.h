//
//  Scene01.h
//  SimpleSTG
//
//  Created by 海下 直哉 on 2015/02/03.
//
//

#include "GameScene.h"
#include "TaskManager.h"

class Scene01 : public GameScene{
public:
    void Init(cocos2d::Layer &layer);
    void RunScene();
private:
    int frame;
    int count;
    TaskManager *taskManager;
    void PushEnemy(cocos2d::Layer &layer);
    void PushBullet(cocos2d::Layer &layer);
};
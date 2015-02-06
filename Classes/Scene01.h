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
    int delay;
    int count;
    const int height = 1280;
    const int width = 800;
    cocos2d::Layer &layer;
    TaskManager *taskManager;
    void PushEnemy(cocos2d::Layer &layer);
    void PushBullet(cocos2d::Layer &layer);
    Mover* PopEnemy(const int enemyNum, const std::string enemyName);
    void SetEnemyParam(Mover *enemy, cocos2d::Point position, const float enemyParam[]);
};
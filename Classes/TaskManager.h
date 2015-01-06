//
//  TaskManager.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#ifndef __Getsuyoubi__TaskManager__
#define __Getsuyoubi__TaskManager__

#include <vector>
#include <iostream>
#include "Mover.h"

using namespace cocos2d;

class TaskManager {
public:
    static TaskManager& getInstance();

    TaskManager();
    TaskManager(const TaskManager &other){}
    TaskManager &operator=(const TaskManager &other){}
    
    Mover *player;
    Layer *sceneLayer;
    std::vector<Mover *> bulletManager;
    std::vector<Mover *> enemyManager;
    
    void AddBulletTask(Mover *bullet, Point playerPoint);
    void AddEnemyTask(Mover &enemy);
    void DoTask(std::vector<Mover *> &list, Layer &sceneLayer);
    void BulletCollistion(Mover *bullet);
};
#endif /* defined(__Getsuyoubi__TaskManager__) */

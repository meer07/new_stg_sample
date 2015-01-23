#pragma once
#include <cocos2d.h>
#include <vector>
#include "Mover.h"

class TaskManager {
public:
    static TaskManager& getInstance();

    TaskManager();
    TaskManager(const TaskManager &other){}
    TaskManager &operator=(const TaskManager &other){}
    
    Mover *player;
    cocos2d::Layer *sceneLayer;
    std::vector<Mover *> playerBulletManager;
    std::vector<Mover *> bulletManager;
    std::vector<Mover *> enemyManager;
    
    void AddBulletTask(std::vector<Mover *> &list, Mover *bullet, cocos2d::Point playerPoint);
    void AddEnemyTask(Mover &enemy);
    void DoTask(std::vector<Mover *> &list, cocos2d::Layer &sceneLayer);
    void BulletCollistion(Mover *bullet);
};
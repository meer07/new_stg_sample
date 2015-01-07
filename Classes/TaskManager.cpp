//
//  TaskManager.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#include "TaskManager.h"

// シングルトンで実装
TaskManager& TaskManager::getInstance(){
    static TaskManager instance;
    return instance;
}

TaskManager::TaskManager(){
    // あらかじめメモリ領域を確保する
    playerBulletManager.reserve(100);
    enemyManager.reserve(100);
    bulletManager.reserve(200);
}

void TaskManager::AddBulletTask(std::vector<Mover *> &list, Mover *bullet, Point playerPoint){
    sceneLayer->addChild(bullet);
    bullet->cocos2d::Node::setPosition(playerPoint);
    bulletManager.push_back(std::move(bullet));
}

void TaskManager::AddEnemyTask(Mover &enemy){
    sceneLayer->addChild(&enemy);
    enemyManager.push_back(&enemy);
}

// vectorを走査し、Moveメソッドを通じてそれぞれのタスクを実行する
void TaskManager::DoTask(std::vector<Mover *> &list, Layer &sceneLayer)
{
    std::vector<Mover *>::iterator i;
    for (i = list.begin(); i != list.end();)
    {
        // そもそもリストが空のときループを抜ける
        if (list.empty()) {
            break;
        }
        if ((*i)->isAlive == false)
        {
            sceneLayer.removeChild(*i);
            list.erase(std::remove(list.begin(), list.end(), *i),list.end());
        }
        else
        {
            (*i)->Move();
            i++; // eraseしないときだけインクリメントする
        }
    }
}

void TaskManager::BulletCollistion(Mover *bullet){
    std::vector<Mover *>::iterator i;
    for(i = enemyManager.begin(); i != enemyManager.end(); ++i){
        Rect bulletrect = bullet->boundingBox();
        Rect enemyrect = (*i)->boundingBox();
        
        // 自機の弾かつ敵と衝突している時、生存フラグを下ろす。
        if ((*i)->getTag() == 4 && bulletrect.intersectsRect(enemyrect)) {
            std::cout << "Hitt!!" << std::endl;
            (*i)->isAlive = false;
            bullet->isAlive = false;
        }
    }
}
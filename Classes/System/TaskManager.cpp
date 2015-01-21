//
//  TaskManager.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#include "TaskManager.h"
#include "GameData.h"
#include <iostream>

// シングルトンで実装
TaskManager& TaskManager::getInstance()
{
    static TaskManager instance;
    return instance;
}

TaskManager::TaskManager()
{
    // あらかじめメモリ領域を確保する
    playerBulletManager.reserve(100);
    enemyManager.reserve(100);
    bulletManager.reserve(200);
}

// 弾を追加
void TaskManager::AddBulletTask(std::vector<Mover *> &list, Mover *bullet, cocos2d::Point playerPoint)
{
    sceneLayer->addChild(bullet);
    bullet->cocos2d::Node::setPosition(playerPoint);
    bulletManager.push_back(std::move(bullet));
}

// 敵を追加
void TaskManager::AddEnemyTask(Mover &enemy)
{
    sceneLayer->addChild(&enemy);
    enemyManager.push_back(&enemy);
}

// vectorを走査し、Moveメソッドを通じてそれぞれのタスクを実行する
void TaskManager::DoTask(std::vector<Mover *> &list, cocos2d::Layer &sceneLayer)
{
    std::vector<Mover *>::iterator i;
    for (i = list.begin(); i != list.end();)
    {
        // そもそもリストが空のときループを抜ける
        if (list.empty()) {
            break;
        }
        
        // 生存フラグが負であるとき削除
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

void TaskManager::BulletCollistion(Mover *bullet)
{
    std::vector<Mover *>::iterator i;
    for(i = enemyManager.begin(); i != enemyManager.end(); ++i){
        cocos2d::Rect bulletrect = bullet->boundingBox();
        cocos2d::Rect enemyrect = (*i)->boundingBox();
        
        // 自機の弾と敵との衝突判定
        if ((*i)->getTag() == 4 && bulletrect.intersectsRect(enemyrect))
        {
            (*i)->hitpoint--;
            
            // HPが0の時、生存フラグを下ろす。
            if ((*i)->hitpoint < 0)
            {
                (*i)->Destroy();
                GameData::getInstance().score += (*i)->score;
            }
            bullet->isAlive = false;
        }
    }
}
//
//  GameScene.cpp
//  SimpleSTG
//
//  Created by 海下 直哉 on 2015/02/03.
//
//

#include "GameScene.h"
#include "TaskManager.h"
#include "Enemy01.h"
#include "Enemy02.h"
#include "Enemy03.h"
#include "Enemy04.h"
#include "MidEnemy01.h"
#include "Boss01.h"
#include "Bullet.h"
#include "PlayerBullet.h"
#include <vector>

Mover* GameScene::GetEnemy(const int enemyNum, const std::string enemyName)
{
    std::vector<Mover *>::iterator i;
    for (i = TaskManager::objectContainer.begin(); i == TaskManager::objectContainer.end();)
    {
        if (!(*i)->isAlive && (*i)->getName() == enemyName) {
            (*i)->setVisible(true);
            (*i)->isAlive = true;
            return (*i);
        }
    }
    
    auto enemy = CreateEnemy(enemyNum);
    return enemy;
}

// 対応する番号で生成する敵を判別
Mover* GameScene::CreateEnemy(const int enemyNum)
{
    float enemyParam[4] = {0,0,0,0};
    float shotParam[3] = {0,0,0};
    switch (enemyNum) {
        case 1:
            return Enemy01::create(enemyParam, shotParam, "enemy.png");
            break;
        case 2:
            return Enemy02::create(enemyParam, shotParam, "enemy02.png");
            break;
        case 3:
            return Enemy03::create(enemyParam, shotParam, "enemy03.png");
            break;
        case 4:
            return Enemy04::create(enemyParam, shotParam, "enemy04.png");
            break;
        case 5:
            return MidEnemy01::create(enemyParam, shotParam, "midenemy01.png");
            break;
        case 6:
            return Boss01::create("boss01.png");
            break;
        default:
            cocos2d::log("Error!! Index Out of Range.");
            return NULL;
            break;
    }
}

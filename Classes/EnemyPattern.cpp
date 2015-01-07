//
//  EnemyPattern.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/07.
//
//

#include "EnemyPattern.h"

// 左端から登場
void EnemyPattern::EnemyPattern01(float param[], int limit, float makePointY)
{
    Enemy02 *enemy2 = Enemy02::create(param, "test_enemy.png");
    
    for (int i = 1; i <= limit; i++)
    {
        enemy2->setPosition(enemy2->getTextureRect().size.width/2, makePointY - enemy2->getTextureRect().size.height/2);
        TaskManager::getInstance().AddEnemyTask(*enemy2);
    }
}

// 右端から登場
void EnemyPattern::EnemyPattern02(float param[], int limit, float makePointY)
{
    Enemy02 *enemy2 = Enemy02::create(param, "test_enemy.png");
    
    for (int i = 1; i <= limit; i++)
    {
        enemy2->setPosition(Director::getInstance()->getWinSize().width - enemy2->getTextureRect().size.width/2, makePointY - enemy2->getTextureRect().size.height/2);
        TaskManager::getInstance().AddEnemyTask(*enemy2);
    }
}
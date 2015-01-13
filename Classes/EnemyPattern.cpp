//
//  EnemyPattern.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/07.
//
//

#include "EnemyPattern.h"
#include "TaskManager.h"
#include "Enemy01.h"
#include "Enemy02.h"
#include "Enemy03.h"

// 左端から登場
void EnemyPattern::EnemyPattern01(const float enemyParam[], const float shotParam[], float makePointY)
{
    Enemy02 *enemy2 = Enemy02::create(enemyParam, shotParam, "test_enemy.png");
    
    
    enemy2->setPosition(enemy2->getTextureRect().size.width/2, makePointY - enemy2->getTextureRect().size.height/2);
    TaskManager::getInstance().AddEnemyTask(*enemy2);
}

// 右端から登場
void EnemyPattern::EnemyPattern02(const float enemyParam[], const float shotParam[], float makePointY)
{
    Enemy02 *enemy2 = Enemy02::create(enemyParam, shotParam, "test_enemy.png");
    
    enemy2->setPosition(Director::getInstance()->getWinSize().width - enemy2->getTextureRect().size.width, makePointY - enemy2->getTextureRect().size.height/2);
    
    TaskManager::getInstance().AddEnemyTask(*enemy2);
}

// 上から登場(直線弾)
void EnemyPattern::EnemyPattern03(const float enemyParam[], const float shotParam[], float makePointX)
{
    Enemy01 *enemy = Enemy01::create(enemyParam, shotParam, "test_enemy.png");
    enemy->setPosition(makePointX, Director::getInstance()->getWinSize().height - enemy->getTextureRect().size.height/2);
    
    TaskManager::getInstance().AddEnemyTask(*enemy);
}

// 上から登場(自機狙い)
void EnemyPattern::EnemyPattern04(const float enemyParam[], const float shotParam[], float makePointX)
{
    Enemy02 *enemy2 = Enemy02::create(enemyParam, shotParam, "test_enemy.png");
    enemy2->setPosition(makePointX, Director::getInstance()->getWinSize().height - enemy2->getTextureRect().size.height/2);
    
    TaskManager::getInstance().AddEnemyTask(*enemy2);
}

// 上から登場(3way)
void EnemyPattern::EnemyPattern05(const float enemyParam[], const float shotParam[], float makePointX)
{
    Enemy03 *enemy3 = Enemy03::create(enemyParam, shotParam, "test_enemy.png");
    enemy3->setPosition(makePointX, Director::getInstance()->getWinSize().height - enemy3->getTextureRect().size.height/2);
    
    TaskManager::getInstance().AddEnemyTask(*enemy3);
}
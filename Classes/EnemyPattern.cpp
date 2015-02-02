#include "EnemyPattern.h"
#include "TaskManager.h"
#include "Enemy01.h"
#include "Enemy02.h"
#include "Enemy03.h"
#include "Enemy04.h"
#include "MidEnemy01.h"
#include "MidEnemy02.h"
#include "Meteorite.h"
#include <iostream>

// 左端から登場
void EnemyPattern::EnemyPattern01(const float enemyParam[], const float shotParam[], float makePointY)
{
    Enemy02 *enemy2 = Enemy02::create(enemyParam, shotParam, "enemy02.png");
    cocos2d::Point point = cocos2d::Point(enemy2->getTextureRect().size.width/2, makePointY - enemy2->getTextureRect().size.height/2);
    enemy2->setPosition(point);
    enemy2->positionId = point.y/512;
    enemy2->setRotation(0);
    
    TaskManager::getInstance()->AddEnemyTask(*enemy2);
}

// 右端から登場
void EnemyPattern::EnemyPattern02(const float enemyParam[], const float shotParam[], float makePointY)
{
    Enemy02 *enemy2 = Enemy02::create(enemyParam, shotParam, "enemy02.png");
    cocos2d::Point point = cocos2d::Point(cocos2d::Director::getInstance()->getWinSize().width - enemy2->getTextureRect().size.width, makePointY - enemy2->getTextureRect().size.height/2);
    enemy2->positionId = point.y/512;
    enemy2->setPosition(point);
    
    enemy2->setRotation(180);
    
    TaskManager::getInstance()->AddEnemyTask(*enemy2);
}

// 上から登場(直線弾)
void EnemyPattern::EnemyPattern03(const float enemyParam[], const float shotParam[], float makePointX)
{
    Enemy01 *enemy = Enemy01::create(enemyParam, shotParam, "enemy.png");
    cocos2d::Point point = cocos2d::Point(makePointX, cocos2d::Director::getInstance()->getWinSize().height - enemy->getTextureRect().size.height/2);
    enemy->setPosition(point);
    enemy->positionId = point.y/512;
    enemy->setRotation(270);
    
    TaskManager::getInstance()->AddEnemyTask(*enemy);
}

// 上から登場(自機狙い)
void EnemyPattern::EnemyPattern04(const float enemyParam[], const float shotParam[], float makePointX)
{
    Enemy02 *enemy2 = Enemy02::create(enemyParam, shotParam, "enemy02.png");
    cocos2d::Point point = cocos2d::Point(makePointX, cocos2d::Director::getInstance()->getWinSize().height - enemy2->getTextureRect().size.height/2);
    enemy2->setPosition(point);
    enemy2->positionId = point.y/512;
    enemy2->setRotation(90);
    std::cout << enemy2->getRotation() << std::endl;
    
    TaskManager::getInstance()->AddEnemyTask(*enemy2);
}

// 上から登場(3way)
void EnemyPattern::EnemyPattern05(const float enemyParam[], const float shotParam[], float makePointX)
{
    Enemy03 *enemy3 = Enemy03::create(enemyParam, shotParam, "enemy03.png");
    cocos2d::Point point = cocos2d::Point(makePointX, cocos2d::Director::getInstance()->getWinSize().height - enemy3->getTextureRect().size.height/2);
    enemy3->setPosition(point);
    enemy3->positionId = point.y/512;
    enemy3->setRotation(90);
    
    TaskManager::getInstance()->AddEnemyTask(*enemy3);
}

// 上から登場(誘導敵)
void EnemyPattern::EnemyPattern06(const float enemyParam[], const float shotParam[], float makePointX)
{
    
    Enemy04 *enemy4 = Enemy04::create(enemyParam, shotParam, "enemy04.png");
    cocos2d::Point point = cocos2d::Point(makePointX, cocos2d::Director::getInstance()->getWinSize().height - enemy4->getTextureRect().size.height/2);
    enemy4->setPosition(point);
    enemy4->positionId = point.y/512;
    enemy4->setRotation(270);
    
    TaskManager::getInstance()->AddEnemyTask(*enemy4);
}

// 左端から登場(誘導敵)
void EnemyPattern::EnemyPattern07(const float enemyParam[], const float shotParam[], float makePointY)
{
    Enemy04 *enemy4 = Enemy04::create(enemyParam, shotParam, "enemy04.png");
    cocos2d::Point point = cocos2d::Point(enemy4->getTextureRect().size.width/2, makePointY - enemy4->getTextureRect().size.height/2);
    enemy4->setPosition(point);
    enemy4->positionId = point.y/512;
    enemy4->setRotation(0);
    
    TaskManager::getInstance()->AddEnemyTask(*enemy4);
}

// 右端から登場(誘導敵)
void EnemyPattern::EnemyPattern08(const float enemyParam[], const float shotParam[], float makePointY)
{
    Enemy04 *enemy4 = Enemy04::create(enemyParam, shotParam, "enemy04.png");
    cocos2d::Point point = cocos2d::Point(cocos2d::Director::getInstance()->getWinSize().width - enemy4->getTextureRect().size.width, makePointY - enemy4->getTextureRect().size.height/2);
    enemy4->setPosition(point);
    enemy4->positionId = point.y/512;
    enemy4->setRotation(180);
    
    TaskManager::getInstance()->AddEnemyTask(*enemy4);
}


// 上から中型敵01
void EnemyPattern::EnemyPattern09(const float enemyParam[], const float shotParam[], float makePointX)
{
	MidEnemy01 *enemy = MidEnemy01::create(enemyParam, shotParam, "midenemy01.png");
    cocos2d::Point point = cocos2d::Point(makePointX, cocos2d::Director::getInstance()->getWinSize().height - enemy->getTextureRect().size.height / 2);
	enemy->setPosition(point);
    enemy->positionId = point.y/512;
	enemy->setRotation(90);

	TaskManager::getInstance()->AddEnemyTask(*enemy);
}

// 上から中型敵02
void EnemyPattern::EnemyPattern10(const float enemyParam[], const float shotParam[], float makePointX)
{
	MidEnemy02 *enemy = MidEnemy02::create(enemyParam, shotParam, "midenemy02.png");
    cocos2d::Point point = cocos2d::Point(makePointX, cocos2d::Director::getInstance()->getWinSize().height - enemy->getTextureRect().size.height / 2);
	enemy->setPosition(point);
    enemy->positionId = point.y/512;
	enemy->setRotation(270);

	TaskManager::getInstance()->AddEnemyTask(*enemy);
}
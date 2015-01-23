#include "EnemyPattern.h"
#include "TaskManager.h"
#include "Enemy01.h"
#include "Enemy02.h"
#include "Enemy03.h"
#include "Enemy04.h"
#include <iostream>

// 左端から登場
void EnemyPattern::EnemyPattern01(const float enemyParam[], const float shotParam[], float makePointY)
{
    //std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy02.png");
    
    Enemy02 *enemy2 = Enemy02::create(enemyParam, shotParam, "enemy02.png");
    
    enemy2->setPosition(enemy2->getTextureRect().size.width/2, makePointY - enemy2->getTextureRect().size.height/2);
    
    enemy2->setRotation(0);
    
    TaskManager::getInstance().AddEnemyTask(*enemy2);
}

// 右端から登場
void EnemyPattern::EnemyPattern02(const float enemyParam[], const float shotParam[], float makePointY)
{
    //std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy02.png");
    
    Enemy02 *enemy2 = Enemy02::create(enemyParam, shotParam, "enemy02.png");
    
    enemy2->setPosition(cocos2d::Director::getInstance()->getWinSize().width - enemy2->getTextureRect().size.width, makePointY - enemy2->getTextureRect().size.height/2);
    
    enemy2->setRotation(180);
    
    TaskManager::getInstance().AddEnemyTask(*enemy2);
}

// 上から登場(直線弾)
void EnemyPattern::EnemyPattern03(const float enemyParam[], const float shotParam[], float makePointX)
{
    //std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy.png");
    
    Enemy01 *enemy = Enemy01::create(enemyParam, shotParam, "enemy.png");
    enemy->setPosition(makePointX, cocos2d::Director::getInstance()->getWinSize().height - enemy->getTextureRect().size.height/2);
    
    enemy->setRotation(270);
    
    TaskManager::getInstance().AddEnemyTask(*enemy);
}

// 上から登場(自機狙い)
void EnemyPattern::EnemyPattern04(const float enemyParam[], const float shotParam[], float makePointX)
{
    //std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy02.png");
    Enemy02 *enemy2 = Enemy02::create(enemyParam, shotParam, "enemy02.png");
    enemy2->setPosition(makePointX, cocos2d::Director::getInstance()->getWinSize().height - enemy2->getTextureRect().size.height/2);
    
    enemy2->setRotation(90);
    std::cout << enemy2->getRotation() << std::endl;
    
    TaskManager::getInstance().AddEnemyTask(*enemy2);
}

// 上から登場(3way)
void EnemyPattern::EnemyPattern05(const float enemyParam[], const float shotParam[], float makePointX)
{
    //std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy03.png");
    Enemy03 *enemy3 = Enemy03::create(enemyParam, shotParam, "enemy03.png");
    enemy3->setPosition(makePointX, cocos2d::Director::getInstance()->getWinSize().height - enemy3->getTextureRect().size.height/2);
    
    enemy3->setRotation(90);
    
    TaskManager::getInstance().AddEnemyTask(*enemy3);
}

// 上から登場(誘導敵)
void EnemyPattern::EnemyPattern06(const float enemyParam[], const float shotParam[], float makePointX)
{
    //std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy04.png");
    
    Enemy04 *enemy4 = Enemy04::create(enemyParam, shotParam, "enemy04.png");
    
    enemy4->setPosition(makePointX, cocos2d::Director::getInstance()->getWinSize().height - enemy4->getTextureRect().size.height/2);
    
    enemy4->setRotation(270);
    
    TaskManager::getInstance().AddEnemyTask(*enemy4);
}

// 左端から登場(誘導敵)
void EnemyPattern::EnemyPattern07(const float enemyParam[], const float shotParam[], float makePointY)
{
    //std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy04.png");
    
    Enemy04 *enemy4 = Enemy04::create(enemyParam, shotParam, "enemy04.png");
    
    enemy4->setPosition(enemy4->getTextureRect().size.width/2, makePointY - enemy4->getTextureRect().size.height/2);
    
    enemy4->setRotation(0);
    
    TaskManager::getInstance().AddEnemyTask(*enemy4);
}

// 右端から登場(誘導敵)
void EnemyPattern::EnemyPattern08(const float enemyParam[], const float shotParam[], float makePointY)
{
    //std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy04.png");
    
    Enemy04 *enemy4 = Enemy04::create(enemyParam, shotParam, "enemy04.png");
    
    enemy4->setPosition(cocos2d::Director::getInstance()->getWinSize().width - enemy4->getTextureRect().size.width, makePointY - enemy4->getTextureRect().size.height/2);
    
    enemy4->setRotation(180);
    
    TaskManager::getInstance().AddEnemyTask(*enemy4);
}

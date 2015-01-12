//
//  EnemyMissle.cpp
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/12.
//
//

#include "EnemyMissle.h"
#include "TaskManager.h"

EnemyMissle* EnemyMissle::create(const float param[], std::string fileName)
{
    EnemyMissle *missle = new EnemyMissle();
    
    missle->hitpoint = 2;
    
    missle->speed = param[0];
    missle->speedRate = param[1];
    missle->angle = param[2];
    missle->isAlive = true;
    missle->setTag(3);
    
    missle->moveDelay = param[3];
    missle->angleRange = param[4];
    
    
    if (missle && missle->initWithFile(fileName)) {
        missle->autorelease();
        missle->retain();
        return missle;
    }
    
    CC_SAFE_DELETE(missle);
    return NULL;
}

void EnemyMissle::Move()
{
    MovePattern();
    MoveBase();
    Collision();
}

void EnemyMissle::MovePattern()
{
    // 自機に向かって回転
    if (moveDelay) {
        Vec2 playerPosition = TaskManager::getInstance().player->getPosition();
        Vec2 enemyPosition = this->getPosition();
        float bulletAngle = CC_RADIANS_TO_DEGREES(atan2f(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x));
        this->setRotation(bulletAngle);
    }
    else
    {
        moveDelay--;
    }
}

void EnemyMissle::Collision()
{
    Rect bulletrect = this->boundingBox();
    Rect playerrect = TaskManager::getInstance().player->boundingBox();
    
    if(bulletrect.intersectsRect(playerrect))
    {
        TaskManager::getInstance().player->isAlive = false;
        this->isAlive = false;
        //std::cout << "Miss!!" << std::endl;
    }
}
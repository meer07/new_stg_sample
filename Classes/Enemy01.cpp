//
//  Enemy01.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/06.
//
//

#include "Enemy01.h"

Enemy01* Enemy01::create(const float param[], std::string fileName)
{
    Enemy01 *enemy = new Enemy01();
    enemy->speed = param[0];
    enemy->speedRate = param[1];
    enemy->angle = param[2];
    enemy->isAlive = true;
    enemy->shotDelay = 60;
    enemy->setTag(4);
    enemy->moveDelay = 60;
    enemy->shotLimit = 3;
    
    if (enemy && enemy->initWithFile(fileName))
    {
        enemy->autorelease();
        enemy->retain();
        return enemy;
    }
    
    CC_SAFE_DELETE(enemy);
    return NULL;
}

void Enemy01::Move()
{
    MovePattern();
    MoveBase();
    Shot();
}

void Enemy01::Shot()
{
    if (shotDelay <= 0 && shotLimit > 0)
    {
        shotParam[0] = 5;
        shotParam[1] = 1;
        shotParam[2] = -90;
        
        TaskManager::getInstance().AddBulletTask(TaskManager::getInstance().bulletManager, Bullet::create(shotParam, "enemy_bullet01.png"), this->getPosition());
        shotDelay = oneSec;
        shotLimit--;
    }
    else
    {
        shotDelay--;
    }
}

void Enemy01::MovePattern(){}

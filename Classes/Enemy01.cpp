//
//  Enemy01.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/06.
//
//

#include "Enemy01.h"

Enemy01* Enemy01::create(const float enemyParam[], const float shotParam[],std::string fileName)
{
    Enemy01 *enemy = new Enemy01();
    // 敵本体のパラメータ
    enemy->hitpoint = 1;
    enemy->speed = enemyParam[0];
    enemy->speedRate = enemyParam[1];
    enemy->angle = enemyParam[2];
    enemy->angleRate = enemyParam[3];
    enemy->isAlive = true;
    enemy->setTag(4);
    
    // ショットのパラメータ
    enemy->shotDelay = enemy->shotDelayTmp = shotParam[0];
    enemy->shotLimit = shotParam[1];
    enemy->moveDelay = enemy->moveDelayTmp = shotParam[2];
    enemy->moveLimit = shotParam[3];
    
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
        float shotParam[3] = {5, 1, -90};
        
        TaskManager::getInstance().AddBulletTask(TaskManager::getInstance().bulletManager, Bullet::create(shotParam, "enemy_bullet01.png"), this->getPosition());
        shotDelay = shotDelayTmp;
        shotLimit--;
    }
    else
    {
        shotDelay--;
    }
}

void Enemy01::MovePattern(){}

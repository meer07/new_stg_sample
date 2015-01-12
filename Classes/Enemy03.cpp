//
//  Enemy03.cpp
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/08.
//
//

#include "Enemy03.h"
#include <string.h>

Enemy03* Enemy03::create(const float enemyParam[], const float shotParam[],std::string fileName)
{
    Enemy03 *enemy = new Enemy03();
    
    // 敵本体のパラメータ
    enemy->hitpoint = 10;
    enemy->speed = enemyParam[0];
    enemy->speedRate = enemyParam[1];
    enemy->angle = enemyParam[2];
    enemy->angleRate = enemyParam[3];
    enemy->isAlive = true;
    enemy->setTag(4);
    
    // ショットのパラメータ
    enemy->shotDelay = enemy->shotDelayTmp = shotParam[0];
    enemy->shotLimit = shotParam[1];
    
    // 移動アニメーションのパラメータ
    enemy->moveDelay = enemy->moveDelayTmp = shotParam[2];
    enemy->moveLimit = shotParam[3];
    
    enemy->flag = false;
    
    if (enemy && enemy->initWithFile(fileName)) {
        enemy->autorelease();
        enemy->retain();
        return enemy;
    }
    
    CC_SAFE_DELETE(enemy);

    return NULL;
}

void Enemy03::Move()
{
    MovePattern();
    MoveBase();
    Shot();
}

void Enemy03::Shot()
{
    if (shotDelay <= 0 && shotLimit > 0)
    {
        for (int i = 1; i < 4; i++) {
            float shotParam[3] = {5, 1, static_cast<float>(360 - 45*i)};
            TaskManager::getInstance().AddBulletTask(TaskManager::getInstance().bulletManager, Bullet::create(shotParam, "enemy_bullet01.png"), this->getPosition());
        }
        shotDelay = shotDelayTmp;
        shotLimit--;
    }
    else
    {
        shotDelay--;
    }
}

void Enemy03::MovePattern()
{
    Point nowPoint = this->getPosition();
    if(nowPoint.y < Director::getInstance()->getWinSize().height - 200)
    {
        if (nowPoint.x <= 100)
        {
            flag = true;
        }
        else if (nowPoint.x >= Director::getInstance()->getWinSize().width - 100)
        {
            flag = false;
        }
        
        if (flag)
        {
            this->angle = 0;
            //this->speed = abs(this->speed);
        }
        else
        {
            this->angle = 180;
            //this->speed = -(this->speed);
        }
    }
}
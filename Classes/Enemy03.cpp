#include "Enemy03.h"
#include "TaskManager.h"
#include "Bullet.h"
#include <string.h>

Enemy03* Enemy03::create(const float enemyParam[], std::string fileName)
{
    Enemy03 *enemy = new Enemy03();
    
    // 敵本体のパラメータ
    enemy->hitpoint = 20;
    enemy->score = 150;
    enemy->setParam(enemyParam);
    enemy->isAlive = true;
    enemy->setTag(4);
    enemy->setName("Enemy03");
    
    // ショットのパラメータ
    enemy->shotDelay = 90;
    enemy->shotDelayTmp = 60;
    enemy->shotLimit = 5;
    
    // 移動アニメーションのパラメータ
    enemy->moveDelay = enemy->moveDelayTmp = 0;
    
    enemy->flag = false;
    
    if (enemy && enemy->initWithSpriteFrameName(fileName)) {
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
            //float shotParam[3] = {8, 0, (float)(360 - 45*i)};
			auto bullet = GetBullet("enemy_bullet01.png");
            cocos2d::Point point = this->getPosition();
			bullet->speed = 8;
			bullet->speedRate = 0;
			bullet->angle = (float)(360 - 45 * i);
			bullet->setPosition(point);
            bullet->positionId = point.y/512;
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
    cocos2d::Point nowPoint = this->getPosition();
    if(nowPoint.y < cocos2d::Director::getInstance()->getWinSize().height - 200)
    {
        if (nowPoint.x <= 100)
        {
            flag = true;
        }
        else if (nowPoint.x >= cocos2d::Director::getInstance()->getWinSize().width - 100)
        {
            flag = false;
        }
        
        if (flag)
        {
            this->angle = 0;
        }
        else
        {
            this->angle = 180;
        }
    }
}

void Enemy03::Destroy()
{
    Mover::Destroy();
}
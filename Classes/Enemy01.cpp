#include "Enemy01.h"
#include "Bullet.h"
#include "TaskManager.h"

/*
    直線に動き、敵の進行方向
*/

Enemy01* Enemy01::create(const float enemyParam[], std::string fileName)
{
    Enemy01 *enemy = new Enemy01();
    // 敵本体のパラメータ
    enemy->hitpoint = 1;
    enemy->score = 100;
    enemy->isAlive = true;
    enemy->setParam(enemyParam);
    enemy->setTag(4);
    enemy->setName("Enemy01");
    
    // ショットのパラメータ
    enemy->shotDelay = 60;
    enemy->shotDelayTmp = 60;
    enemy->shotLimit = 3;
    enemy->moveDelay = enemy->moveDelayTmp = 0;
    
    if (enemy && enemy->initWithSpriteFrameName(fileName))
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

// 直線弾
void Enemy01::Shot()
{
    if (shotDelay <= 0 && shotLimit > 0)
    {
		auto bullet = GetBullet("enemy_bullet01.png");
        cocos2d::Point point = this->getPosition();
		bullet->speed = 8;
		bullet->speedRate = 0;
		bullet->angle = this->angle;
		bullet->setPosition(point);
        bullet->positionId = point.y/512;
        shotDelay = shotDelayTmp;
        shotLimit--;
    }
    else
    {
        shotDelay--;
    }
}

void Enemy01::Destroy()
{
    Mover::Destroy();
}

void Enemy01::MovePattern(){}

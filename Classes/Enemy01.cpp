#include "Enemy01.h"
#include "Bullet.h"
#include "TaskManager.h"

Enemy01* Enemy01::create(const float enemyParam[], const float shotParam[], std::string fileName)
{
    Enemy01 *enemy = new Enemy01();
    // 敵本体のパラメータ
    enemy->hitpoint = 1;
    enemy->score = 100;
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
		bullet->angle = -90;
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

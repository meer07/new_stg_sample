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
        float shotParam[3] = {8, 0, -90};
        //std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy_bullet01.png");
        TaskManager::getInstance().AddBulletTask(TaskManager::getInstance().bulletManager, Bullet::create(shotParam, "enemy_bullet01.png"), this->getPosition());
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

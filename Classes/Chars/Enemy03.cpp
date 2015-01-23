#include "Enemy03.h"
#include "TaskManager.h"
#include "Bullet.h"
#include <string.h>

Enemy03* Enemy03::create(const float enemyParam[], const float shotParam[],std::string fileName)
{
    Enemy03 *enemy = new Enemy03();
    
    // 敵本体のパラメータ
    enemy->hitpoint = 20;
    enemy->score = 150;
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
    //enemy->moveLimit = shotParam[3];
    
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
    //std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy_bullet01.png");
    if (shotDelay <= 0 && shotLimit > 0)
    {
        for (int i = 1; i < 4; i++) {
            float shotParam[3] = {8, 0, static_cast<float>(360 - 45*i)};
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
//
//  Boss02.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/16.
//
//

#include "Boss02.h"
#include "EnemyMissle.h"

Boss02* Boss02::create(std::string fileName)
{
    Boss02 *boss = new Boss02();
    
    boss->hitpoint = 200;
    boss->score = 1000;
    boss->speed = 3;
    boss->speedRate = 1;
    boss->angle = 270;
    boss->angleRate = 0;
    boss->isAlive = true;
    boss->setTag(4);
    
    // ショットのパラメータ
    boss->shotDelay = 0;
    boss->shotDelayTmp = 10;
    boss->shotLimit = 0;
    boss->moveDelay = 0;
    boss->moveDelayTmp = 0;
    
    boss->moveFlag = true;
    boss->shotFlag = true;
    
    if (boss && boss->initWithFile(fileName)) {
        boss->autorelease();
        boss->retain();
        return boss;
    }
    
    CC_SAFE_DELETE(boss);
    
    return NULL;
}

void Boss02::Move()
{
    cocos2d::Point nowPoint = this->getPosition();
    MovePattern(nowPoint);
    MoveBase();
    Shot();
}

void Boss02::MovePattern(cocos2d::Point nowPoint)
{
    
    if(nowPoint.y < cocos2d::Director::getInstance()->getWinSize().height - 200)
    {
        this->speed = 0;
    }
    
}

void Boss02::Shot()
{
    std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy_bullet01.png");
    if (shotDelay > 30 && shotDelay < 100)
    {
        // 15秒毎に発射
        if(static_cast<int>(shotDelay) % 15 == 0)
        {
            if(shotFlag)
            {
                float shotAngles[4] = {-30, -10, 10, 30};
                MainShot(shotAngles, 8, 4, fullpath);
                shotFlag = false;
            }
            else
            {
                float shotAngles[5] = {-40, -20, 0, 20, 40};
                MainShot(shotAngles, 8, 5, fullpath);
                shotFlag = true;
            }
        }
    }
    else if (shotDelay > 120 && shotDelay < 250)
    {
        if (static_cast<int>(shotDelay) % 10 == 0) {
            bulletAngle = MakeAngle();
            float shotAngles[1] = {0};
            MainShot(shotAngles, 10, 1, fullpath);
        }
    }
    else if(shotDelay > 250)
    {
        shotDelay = 0;
    }
    else
    {
        bulletAngle = MakeAngle();
    }

    shotDelay++;
}

void Boss02::Destroy(){
}

// 自機狙いway弾
void Boss02::MainShot(float shotAngle[], float shotSpeed, int way, std::string fileName)
{
    for (int a = 0; a < way; a++)
    {
        ShotPattern(shotAngle[a] + bulletAngle, shotSpeed, fileName);
    }
}

void Boss02::ShotPattern(float angle, float shotSpeed, std::string fileName)
{
    float shotParam[3] = {shotSpeed, 1, angle};
    TaskManager::getInstance().AddBulletTask(TaskManager::getInstance().bulletManager, Bullet::create(shotParam, fileName), this->getPosition());
}

float Boss02::MakeAngle()
{
    cocos2d::Vec2 playerPosition = TaskManager::getInstance().player->getPosition();
    cocos2d::Vec2 enemyPosition = this->getPosition();
    return  CC_RADIANS_TO_DEGREES(atan2f(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x));
}
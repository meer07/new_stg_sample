//
//  Boss01.cpp
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/12.
//
//

#include "Boss01.h"
#include "EnemyMissle.h"

Boss01* Boss01::create(std::string fileName)
{
    Boss01 *boss = new Boss01();
    
    boss->hitpoint = 150;
    boss->score = 1000;
    boss->speed = 3;
    boss->speedRate = 1;
    boss->angle = 270;
    boss->angleRate = 0;
    boss->isAlive = true;
    boss->setTag(4);
    
    // ショットのパラメータ
    boss->shotDelay = 120;
    boss->shotDelayTmp = 10;
    boss->shotLimit = 0;
    boss->moveDelay = 0;
    boss->moveDelayTmp = 0;
    //boss->moveLimit = 60;
    
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

void Boss01::Move()
{
    cocos2d::Point nowPoint = this->getPosition();
    MovePattern(nowPoint);
    MoveBase();
    Shot(nowPoint);
}

void Boss01::MovePattern(cocos2d::Point nowPoint)
{
    
    if(nowPoint.y < cocos2d::Director::getInstance()->getWinSize().height - 200)
    {
        if (nowPoint.x <= 100)
        {
            moveFlag = true;
        }
        else if (nowPoint.x >= cocos2d::Director::getInstance()->getWinSize().width - 100)
        {
            moveFlag = false;
        }
        
        if (moveFlag)
        {
            this->angle = 0;
        }
        else
        {
            this->angle = 180;
        }
    }

}

void Boss01::Shot(cocos2d::Point nowPoint)
{
    // ミサイル発射
    if (static_cast<int>(shotDelay) % 30 == 0)
    {
        float shotParam[5] = {5, 2, 0, 30, 0};
        
        for (int i = 0; i < 2; i++)
        {
            shotParam[2] = 180 * i;
            EnemyMissle *missle = EnemyMissle::create(shotParam, "missle.png");
            missle->setPosition(nowPoint.x, nowPoint.y);
            TaskManager::getInstance().AddEnemyTask(*missle);
        }
    }
    else if(static_cast<int>(shotDelay) % 10 == 0) // メインショット発射
    {
        if(shotFlag)
        {
            MainShot(45);
            shotFlag = false;
        }
        else
        {
            MainShot(0);
            shotFlag = true;
        }
        
    }
    shotDelay++;
}

void Boss01::MainShot(float baseAngle)
{
    for (int a = 0; a < 4; a++)
    {
        RotateShot(90 * a + baseAngle);
    }
}

void Boss01::RotateShot(float angle)
{
    float shotParam[3] = {5, 1, angle};
    TaskManager::getInstance().AddBulletTask(TaskManager::getInstance().bulletManager, Bullet::create(shotParam, "enemy_bullet01.png"), this->getPosition());
}
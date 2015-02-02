#include "Boss01.h"
#include "Bullet.h"
#include "TaskManager.h"
#include "EnemyMissle.h"
#include "GameData.h"

Boss01* Boss01::create(std::string fileName)
{
    Boss01 *boss = new Boss01();
    
    boss->hitpoint = 150;
    boss->score = 1000;
    boss->speed = 3;
    boss->speedRate = 0;
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
    
	if (boss && boss->initWithSpriteFrameName(fileName)) {
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
    if ((int)shotDelay % 30 == 0)
    {
        float shotParam[5] = {10, 0, 0, 30, 0};
        
        for (int i = 0; i < 2; i++)
        {
            shotParam[2] = 180 * i;
            EnemyMissle *missle = EnemyMissle::create(shotParam, "missle.png");
            missle->positionId = nowPoint.y/512;
            missle->setPosition(nowPoint.x, nowPoint.y);
            TaskManager::getInstance()->AddEnemyTask(*missle);
        }
    }
    else if((int)shotDelay % 10 == 0) // メインショット発射
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
    //float shotParam[3] = {5, 1, angle};
	auto bullet = TaskManager::getInstance()->GetEnemyBullet();
    cocos2d::Point point = this->getPosition();
	bullet->speed = 5;
	bullet->speedRate = 1;
	bullet->angle = angle;
	bullet->setPosition(point);
    bullet->positionId = point.y/512;
}

void Boss01::Destroy(){
    // 爆発アニメ
	Mover::Destroy();
    // ステージクリア
    GameData::getInstance()->stageClear01 = true;
}
#include "Boss02.h"
#include "Bullet.h"
#include "TaskManager.h"
#include "EnemyMissle.h"
#include <iostream>

Boss02* Boss02::create(std::string fileName)
{
    Boss02 *boss = new Boss02();
    
    boss->hitpoint = 200;
    boss->score = 1000;
    boss->speed = 3;
    boss->speedRate = 0;
    boss->angle = 270;
    boss->angleRate = 0;
    boss->isAlive = true;
    boss->setTag(4);
    boss->setName("Boss02");
    
    // ショットのパラメータ
    boss->shotDelay = 0;
    boss->shotDelayTmp = 10;
    boss->shotLimit = 0;
    boss->moveDelay = 0;
    boss->moveDelayTmp = 0;
    
    boss->moveFlag = true;
    boss->shotFlag = true;
    boss->shotcount = 0;
	boss->setRotation(270);
    
	if (boss && boss->initWithSpriteFrameName(fileName)) {
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
    if (this->hitpoint > 100)
	{
        ShotPattern01();
		shotDelay++;
    }
    else if (this->hitpoint == 100)
    {
        shotcount = 0;
        shotDelay = 0;
    }
    else if (this->hitpoint < 100)
    {
        ShotPattern02();
		shotDelay++;
    }
   
}

void Boss02::Destroy(){
	Mover::Destroy();
}

void Boss02::ShotPattern01()
{
    if (shotDelay > 30 && shotDelay < 100)
    {
        // 15フレーム毎に発射
        if((int)shotDelay % 15 == 0)
        {
            bulletAngle = MakeAngle();
            // flagがtrueの時は4way、そうでないときは5way
            if(shotFlag)
            {
                float shotAngles[4] = {-30, -10, 10, 30};
                MainShot01(shotAngles, 8, 0, 4);
                shotFlag = false;
            }
            else
            {
                float shotAngles[5] = {-40, -20, 0, 20, 40};
                MainShot01(shotAngles, 8, 0, 5);
                shotFlag = true;
            }
        }
    }
    else if (shotDelay > 120 && shotDelay < 390)
    {
        if ((int)shotDelay % 15 == 0) {
            /*
             bulletAngle = MakeAngle();
             float shotAngles[1] = {0};
             MainShot01(shotAngles, 10, 0, 1, "enemy_bullet01.png");
             */
            
            float shotAngles2[2] = {(float)(180 + shotcount), (float)(0 - shotcount)};
            for (int i = -1; i < 2; i += 2) {
                bulletAngle = 0;
                float range = this->getTextureRect().size.width * i / 2;
                MainShot01(shotAngles2, 10, range, 2);
            }
            
            if (shotcount >= 180)
            {
                shotFlag = false;
            }
            else if(shotcount <= 0)
            {
                shotFlag = true;
            }
            
            if (shotFlag) {
                shotcount += 10;
            }
            else
            {
                shotcount -= 10;
            }
        }
    }
    else if(shotDelay > 400)
    {
        shotcount = 0;
        shotDelay = 0;
    }
}

void Boss02::ShotPattern02()
{
	if (shotDelay > 10 && shotDelay < 130)
	{

		if ((int)shotDelay % 10 == 0)
		{
			//std::cout << shotDelay << std::endl;
			float shotAngles[3] = { -30.0f, 0.0f, 30.0f };
			bulletAngle = 90 * shotcount;
			MainShot01(shotAngles, 10, 0, 3);
			//shotLimit++;
			shotcount++;

			/*
			if (shotLimit >= 3)
			{
				shotcount++;
				shotLimit = 0;
			}
			*/
		}
	}
	else if (shotDelay == 130)
	{
		shotcount = 0;
		bulletAngle = 0;
	}
	else if (shotDelay > 150 && shotDelay < 650)
	{
		if ((int)shotDelay % 25 == 0)
		{
			float shotAngles[3] = { 270.0f+45.0f + shotcount, 270.0f + shotcount, 270.0f-45.0f + shotcount};
			float shotPosition[3] = { -this->getTextureRect().size.width*2, 0 ,this->getTextureRect().size.width*2};

			for (int i = 0; i < 3; i++) {
				MainShot01(shotAngles, 10, shotPosition[i], 3);
			}

			if (shotDelay > 200 && shotDelay < 350)
			{
				shotcount += 10;
			}
			else if (shotDelay > 360 && shotDelay < 650)
			{
				shotcount -= 10;
			}
		}
	}
	else if (shotDelay == 660)
	{
		shotDelay = 0;
		shotcount = 0;
	}
}


// 自機狙いway弾
void Boss02::MainShot01(float shotAngles[], float shotSpeed, float pointX, int way)
{

    for (int a = 0; a < way; a++)
    {
       // float shotParam[3] = {shotSpeed, 0, shotAngles[a] + bulletAngle};
        auto bullet = GetBullet("enemy_bullet01.png");
        cocos2d::Point point = this->getPosition();
        point = cocos2d::Point(point.x + pointX, point.y);
		bullet->speed = shotSpeed;
		bullet->speedRate = 0;
		bullet->angle = shotAngles[a] + bulletAngle;
		bullet->setPosition(point);
        bullet->positionId = point.y/512;
    }
}


float Boss02::MakeAngle()
{
    cocos2d::Vec2 playerPosition = TaskManager::player->getPosition();
    cocos2d::Vec2 enemyPosition = this->getPosition();
    return  CC_RADIANS_TO_DEGREES(atan2f(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x));
}
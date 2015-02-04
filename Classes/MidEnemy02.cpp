#include "MidEnemy02.h"
#include "Bullet.h"
#include "TaskManager.h"
#include "EffectManager.h"

MidEnemy02* MidEnemy02::create(const float enemyParam[], const float shotParam[], std::string fileName)
{
	MidEnemy02 *enemy = new MidEnemy02();
	// 敵本体のパラメータ
	enemy->hitpoint = 50;
	enemy->score = 500;
	enemy->speed = enemyParam[0];
	enemy->speedRate = enemyParam[1];
	enemy->angle = enemyParam[2];
	enemy->angleRate = enemyParam[3];
	enemy->isAlive = true;
	enemy->setTag(4);
    enemy->setName("MidEnemy02");

	// ショットのパラメータ
	enemy->shotDelay = 0;
	enemy->shotDelayTmp = shotParam[0];
	enemy->shotLimit = shotParam[1];
	enemy->moveDelay = enemy->moveDelayTmp = shotParam[2];

	enemy->shotCount = 0;
	enemy->flag = false;

	if (enemy && enemy->initWithSpriteFrameName(fileName))
	{
		enemy->autorelease();
		enemy->retain();
		return enemy;
	}

	CC_SAFE_DELETE(enemy);
	return NULL;
}

void MidEnemy02::Move()
{
	MovePattern();
	MoveBase();
	Shot();
}

void MidEnemy02::MovePattern()
{
	cocos2d::Point nowPoint = this->getPosition();
	if (nowPoint.y < cocos2d::Director::getInstance()->getWinSize().height - 100)
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

void MidEnemy02::Shot()
{
	// 左端から3回発射
	if (shotDelay > shotDelayTmp && shotDelay < shotDelayTmp + 150) {
        if (static_cast<int>(shotDelay) % 10 == 0) {
            float shotParam[3] = { 8, 0, 270 };
            int shotRange[2] = {-2, 2};
            float range = this->getTextureRect().size.width * shotRange[shotCount] / 3;      
			cocos2d::Point nowPoint = this->getPosition();
			cocos2d::Point newPoint = cocos2d::Point(nowPoint.x + range, nowPoint.y);

			auto bullet = GetBullet("enemy_bullet01.png");
			bullet->speed = 8;
			bullet->speedRate = 0;
			bullet->angle = 270;
			bullet->setPosition(newPoint);
			bullet->positionId = newPoint.y / 512;

            shotCount++;
            
            if (shotCount > 1) {
                shotCount = 0;
            }
        }
	}
	else if (shotDelay > shotDelayTmp)
	{
		shotCount = 0;
		shotDelay = 0;
	}

	shotDelay++;
}

void MidEnemy02::Destroy()
{
	Mover::Destroy();
}

float MidEnemy02::GetAngle()
{
	cocos2d::Vec2 playerPosition = TaskManager::player->getPosition();
	cocos2d::Vec2 enemyPosition = this->getPosition();
	float bulletAngle = CC_RADIANS_TO_DEGREES(atan2f(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x));
	return bulletAngle;
}
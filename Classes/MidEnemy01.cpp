#include "MidEnemy01.h"
#include "EffectManager.h"
#include "Bullet.h"
#include "TaskManager.h"

MidEnemy01* MidEnemy01::create(const float enemyParam[], const float shotParam[], std::string fileName)
{
    MidEnemy01 *enemy = new MidEnemy01();
    // 敵本体のパラメータ
    enemy->hitpoint = 50;
    enemy->score = 500;
    enemy->speed = enemyParam[0];
    enemy->speedRate = enemyParam[1];
    enemy->angle = enemyParam[2];
    enemy->angleRate = enemyParam[3];
    enemy->isAlive = true;
    enemy->setTag(4);
    enemy->setName("MidEnemy01");
    
    // ショットのパラメータ
    enemy->shotDelay = 0;
    enemy->shotDelayTmp = shotParam[0];
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

void MidEnemy01::Move()
{
    MovePattern();
    MoveBase();
    Shot();
}

void MidEnemy01::MovePattern()
{
    if (moveDelay < 0 && angle > 180 && angle < 360 && angleRate != 0) {
        angle += angleRate;
        moveDelay = moveDelayTmp;
    }else{
        moveDelay--;
    }
}

void MidEnemy01::Shot()
{
    // 規定時間に達したら0.5秒に１回発射×5
    if (shotDelay > shotDelayTmp && shotDelay < shotDelayTmp+150) {
		if (static_cast<int>(shotDelay) % 30 == 0)
		{
			for (int i = 1; i < 3; i++) {
				//float shotParam[3] = { 8, 0, GetAngle() };

				auto bullet = GetBullet("enemy_bullet01.png");
				float range = this->getTextureRect().size.width / 2;
				if (i % 2 == 0) {
					range = -range;
				}
				cocos2d::Point nowPoint = this->getPosition();
				cocos2d::Point newPoint = cocos2d::Point(nowPoint.x + range, nowPoint.y + range);

				bullet->speed = 8;
				bullet->speedRate = 0;
				bullet->angle = GetAngle();
				bullet->setPosition(newPoint);
				bullet->positionId = newPoint.y / 512;
			}
		}
    }
    else if(shotDelay > shotDelayTmp)
    {
        shotDelay = 0;
    }
    
    shotDelay++;
}

void MidEnemy01::Destroy()
{
	Mover::Destroy();
}

float MidEnemy01::GetAngle()
{
    cocos2d::Vec2 playerPosition = TaskManager::player->getPosition();
    cocos2d::Vec2 enemyPosition = this->getPosition();
    float bulletAngle = CC_RADIANS_TO_DEGREES(atan2f(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x));
    return bulletAngle;
}
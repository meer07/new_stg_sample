#include "Enemy04.h"
#include "Bullet.h"
#include "TaskManager.h"

Enemy04* Enemy04::create(const float enemyParam[], const float shotParam[], std::string fileName){
    Enemy04 *enemy = new Enemy04();
    
    // 敵本体のパラメータ
    enemy->hitpoint = 1;
    enemy->score = 100;
    enemy->speed = enemyParam[0];
    enemy->speedRate = enemyParam[1];
    enemy->angle = enemyParam[2];
    enemy->angleRate = enemyParam[3];
    enemy->isAlive = true;
    enemy->setTag(4);
    enemy->setName("Enemy04");
    
    // ショットのパラメータ
    enemy->shotDelay = 60;
    enemy->shotDelayTmp = shotParam[0];
    enemy->shotLimit = shotParam[1];
    enemy->moveDelay = enemy->moveDelayTmp = shotParam[2];
    //enemy->moveLimit = shotParam[3];
    
    
    if (enemy && enemy->initWithSpriteFrameName(fileName)) {
        enemy->autorelease();
        enemy->retain();
        return enemy;
    }
    
    CC_SAFE_DELETE(enemy);
    return NULL;
}

void Enemy04::Move(){
    float rotateAngle = rotate();
    MovePattern(rotateAngle);
    MoveBase();
    Shot(rotateAngle);
}

// 自機狙い弾
void Enemy04::Shot(float rotateAngle){
    if (shotDelay <= 0 && shotLimit > 0) {
        //float shotParam[3] = {5, 0, rotateAngle};
		auto bullet = GetBullet("enemy_bullet01.png");
        cocos2d::Point point = this->getPosition();

		bullet->speed = 5;
		bullet->speedRate = 0;
		bullet->angle = rotateAngle;
		bullet->setPosition(point);
        bullet->positionId = point.y / 512;

        shotDelay = shotDelayTmp;
        shotLimit--;
    }else{
        shotDelay--;
    }
}

void Enemy04::MovePattern(float rotateAngle){
    if (moveDelay > 0) {
        this->setRotation(-rotateAngle - angleRate);
        angle = rotateAngle;
    }else{
        moveDelay--;
    }
}

void Enemy04::Destroy()
{
    Mover::Destroy();
}

float Enemy04::rotate()
{
    cocos2d::Vec2 playerPosition = TaskManager::player->getPosition();
    cocos2d::Vec2 enemyPosition = this->getPosition();
    return CC_RADIANS_TO_DEGREES(atan2f(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x));
}

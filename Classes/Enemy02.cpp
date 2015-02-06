#include "Enemy02.h"
#include "Bullet.h"
#include "TaskManager.h"

Enemy02* Enemy02::create(const float enemyParam[], std::string fileName){
    Enemy02 *enemy = new Enemy02();
    
    // 敵本体のパラメータ
    enemy->hitpoint = 1;
    enemy->score = 100;
    enemy->isAlive = true;
    enemy->setParam(enemyParam);
    enemy->setTag(4);
    enemy->setName("Enemy02");
    
    // ショットのパラメータ
    enemy->shotDelay = 90;
    enemy->shotDelayTmp = 60;
    enemy->shotLimit = 2;
    enemy->moveDelay = enemy->moveDelayTmp = 1;
    //enemy->moveLimit = shotParam[3];
    
    
    if (enemy && enemy->initWithSpriteFrameName(fileName)) {
        enemy->autorelease();
        enemy->retain();
        return enemy;
    }
    
    CC_SAFE_DELETE(enemy);
    return NULL;
}

void Enemy02::Move(){
    MovePattern();
    MoveBase();
    Shot();
}

// 自機狙い弾
void Enemy02::Shot(){
    if (shotDelay <= 0 && shotLimit > 0) {
        cocos2d::Vec2 playerPosition = TaskManager::player->getPosition();
        cocos2d::Vec2 enemyPosition = this->getPosition();
        float bulletAngle = CC_RADIANS_TO_DEGREES(atan2f(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x));
        //float shotParam[3] = {8, 0, bulletAngle};
        
		auto bullet = GetBullet("enemy_bullet01.png");
        cocos2d::Point point = this->getPosition();
		bullet->speed = 8;
		bullet->speedRate = 0;
		bullet->angle = bulletAngle;
		bullet->setPosition(point);
        bullet->positionId = point.y/512;

        shotDelay = shotDelayTmp;
        shotLimit--;
    }else{
        shotDelay--;
    }
}

void Enemy02::MovePattern(){
    if (moveDelay < 0 && angle > -90) {
        angle += angleRate;
        moveDelay = moveDelayTmp;
    }else{
        moveDelay--;
    }
}

void Enemy02::Destroy()
{
    Mover::Destroy();
}
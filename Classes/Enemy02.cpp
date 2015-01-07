//
//  Enemy02.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/07.
//
//

#include "Enemy02.h"

Enemy02* Enemy02::create(const float param[], std::string fileName){
    Enemy02 *enemy = new Enemy02();
    enemy->speed = param[0];
    enemy->speedRate = param[1];
    enemy->angle = param[2];
    enemy->angleRate = param[3];
    enemy->isAlive = true;
    enemy->shotDelay = 60;
    enemy->setTag(4);
    enemy->moveDelay = 60;
    enemy->shotLimit = 3;
    
    if (enemy && enemy->initWithFile(fileName)) {
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

void Enemy02::Shot(){
    if (shotDelay <= 0 && shotLimit > 0) {
        Vec2 playerPosition = TaskManager::getInstance().player->getPosition();
        Vec2 enemyPosition = this->getPosition();
        float bulletAngle = CC_RADIANS_TO_DEGREES(atan2f(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x));
        
        shotParam[0] = 5;
        shotParam[1] = 1;
        shotParam[2] = bulletAngle;
        
        TaskManager::getInstance().AddBulletTask(TaskManager::getInstance().bulletManager, Bullet::create(shotParam, "enemy_bullet01.png"), this->getPosition());
        
        shotDelay = oneSec;
        shotLimit--;
    }else{
        shotDelay--;
    }
}

void Enemy02::MovePattern(){
    if (moveDelay < 0 && angle > -90) {
        angle += angleRate;
        moveDelay = oneSec;
    }else{
        moveDelay--;
    }
}

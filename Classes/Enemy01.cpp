//
//  Enemy01.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/06.
//
//

#include "Enemy01.h"

Enemy01* Enemy01::create(const float param[], Layer *sceneLayer_){
    Enemy01 *enemy = new Enemy01();
    enemy->speed = param[0];
    enemy->speedRate = param[1];
    enemy->angle = param[2];
    enemy->isAlive = true;
    enemy->shotDelay = 2.0f;
    enemy->setTag(4);
    
    if (enemy && enemy->initWithFile("test_enemy.png")) {
        enemy->autorelease();
        enemy->retain();
        return enemy;
    }
    
    CC_SAFE_DELETE(enemy);
    return NULL;
}

void Enemy01::Move(){
        MoveBase();
        Shot();
}

void Enemy01::Shot(){
    if (shotDelay <= 0) {
        TaskManager::getInstance().AddBulletTask(std::move(Bullet::create(shotParam, "enemy_bullet01.png")), this->getPosition());
        shotDelay = 2.0f;
    }else{
        shotDelay -= 0.1f;
    }
}

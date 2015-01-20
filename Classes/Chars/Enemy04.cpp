//
//  Enemy04.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/19.
//
//

#include "Enemy04.h"

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
    
    // ショットのパラメータ
    enemy->shotDelay = 60;
    enemy->shotDelayTmp = shotParam[0];
    enemy->shotLimit = shotParam[1];
    enemy->moveDelay = enemy->moveDelayTmp = shotParam[2];
    //enemy->moveLimit = shotParam[3];
    
    
    if (enemy && enemy->initWithFile(fileName)) {
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
        float shotParam[3] = {5, 0, rotateAngle};
        std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy_bullet01.png");
        TaskManager::getInstance().AddBulletTask(TaskManager::getInstance().bulletManager, Bullet::create(shotParam, fullpath), this->getPosition());
        
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
}

float Enemy04::rotate()
{
    cocos2d::Vec2 playerPosition = TaskManager::getInstance().player->getPosition();
    cocos2d::Vec2 enemyPosition = this->getPosition();
    return CC_RADIANS_TO_DEGREES(atan2f(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x));
}

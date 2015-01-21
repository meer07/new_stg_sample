//
//  Enemy02.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/07.
//
//

#include "Enemy02.h"
#include "Bullet.h"
#include "TaskManager.h"

Enemy02* Enemy02::create(const float enemyParam[], const float shotParam[], std::string fileName){
    Enemy02 *enemy = new Enemy02();
    
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
    enemy->shotDelay = enemy->shotDelayTmp = shotParam[0];
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

void Enemy02::Move(){
    MovePattern();
    MoveBase();
    Shot();
}

// 自機狙い弾
void Enemy02::Shot(){
    if (shotDelay <= 0 && shotLimit > 0) {
        cocos2d::Vec2 playerPosition = TaskManager::getInstance().player->getPosition();
        cocos2d::Vec2 enemyPosition = this->getPosition();
        float bulletAngle = CC_RADIANS_TO_DEGREES(atan2f(playerPosition.y - enemyPosition.y, playerPosition.x - enemyPosition.x));
        float shotParam[3] = {8, 0, bulletAngle};
        
        std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy_bullet01.png");
        TaskManager::getInstance().AddBulletTask(TaskManager::getInstance().bulletManager, Bullet::create(shotParam, fullpath), this->getPosition());
        
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
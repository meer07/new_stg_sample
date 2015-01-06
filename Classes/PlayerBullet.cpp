//
//  PlayerBullet.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//  

#include "PlayerBullet.h"
#include <iostream>

PlayerBullet* PlayerBullet::create(float speed, float speedRate, float angle, std::string fileName)
{
    PlayerBullet *bullet = new PlayerBullet();
    bullet->speed = speed;
    bullet->speedRate = speedRate;
    bullet->angle = angle;
    bullet->isAlive = true;
    bullet->setTag(2);
    
    if (bullet && bullet->initWithFile(fileName))
    {
        bullet->autorelease();
        bullet->retain();
        return bullet;
    }
    
    CC_SAFE_DELETE(bullet);
    return NULL;
}

void PlayerBullet::Move(){
    MoveBase();
    Collision();
}

void PlayerBullet::Collision(){
    if (TaskManager::getInstance().enemyManager.size() > 0) {
        TaskManager::getInstance().BulletCollistion(this);
    }
    
}

PlayerBullet::~PlayerBullet(){
    std::cout << "delete" << std::endl;
}
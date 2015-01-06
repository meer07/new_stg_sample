//
//  Player.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#include "Player.h"

Player* Player::create(Layer *sceneLayer_){
    Player* player = new Player();
    
    player->shotSpeed = 10;
    player->shotSpeedRate = 1;
    player->shotAngle = 90;
    player->shotDelay = 2.0f;
    player->isAlive = true;
    player->setTag(1);

    
    if (player && player->initWithFile("player.png")) {
        player->autorelease();
        player->retain();
        return player;
    }
    
    CC_SAFE_DELETE(player);
    return NULL;
}

void Player::Move(){
    Shot();
}

void Player::Shot(){
    if (shotDelay <= 0) {
        PlayerBullet *bullet = PlayerBullet::create(shotSpeed, shotSpeedRate, shotAngle, "enemy_bullet01.png");
        bullet->setPosition(Player::getPosition().x, Player::getPosition().y);
        TaskManager::getInstance().sceneLayer->addChild(bullet);
        TaskManager::getInstance().bulletManager.push_back(std::move(bullet));
        shotDelay = 1.0f;
    }else{
        shotDelay -= 0.1f;
    }
}
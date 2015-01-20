//
//  Player.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#include "Player.h"
#include "PlayerBullet.h"
#include "TaskManager.h"
#include "GameData.h"

Player* Player::create(cocos2d::Layer *sceneLayer_)
{
    Player* player = new Player();
    
    player->shotSpeed = 40;
    player->shotSpeedRate = 0.1f;
    player->shotAngle = 90;
    player->shotDelay = 0;
    player->isAlive = true;
    player->setTag(1);
    player->frame = 120;
    player->muteki = false;

    std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("player.png");
    if (player && player->initWithFile(fullpath))
    {
        player->autorelease();
        player->retain();
        return player;
    }
    
    CC_SAFE_DELETE(player);
    return NULL;
}

void Player::Move()
{
    Shot();
}

void Player::Shot()
{
    if (shotDelay <= 0)
    {
        std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("enemy_bullet02.png");
        PlayerBullet *bullet = PlayerBullet::create(shotSpeed, shotSpeedRate, shotAngle, fullpath);
        bullet->setPosition(Player::getPosition().x, Player::getPosition().y);
        TaskManager::getInstance().sceneLayer->addChild(bullet);
        TaskManager::getInstance().playerBulletManager.push_back(std::move(bullet));
        shotDelay = 5;
    }
    else
    {
        shotDelay--;
    }
}

void Player::Destroy()
{
    if (!muteki) {
        GameData::getInstance().playerHp -= 1;
        muteki = true;
    }else{
        frame--;
    }
    
    if (frame < 0) {
        muteki = false;
        frame = 120; // 2秒
    }
}
#include "Player.h"
#include "PlayerBullet.h"
#include "TaskManager.h"
#include "EffectManager.h"
#include "GameData.h"

Player* Player::create(cocos2d::Layer *sceneLayer_)
{
    Player* player = new Player();
    
    player->shotSpeed = 40;
    player->shotSpeedRate = 0;
    player->shotAngle = 90;
    player->shotDelay = 0;
    player->isAlive = true;
    player->setTag(1);
    player->frame = 60;
    
    if (player && player->initWithSpriteFrameName("player.png"))
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
    
    if (isAlive == false) {
        frame--;
    }
    
    if (frame < 0) {
        frame = 60;
        isAlive = true;
    }
}

void Player::Shot()
{
    if (shotDelay <= 0)
    {
		auto *bullet = GetBullet();
        cocos2d::Point point = cocos2d::Point(getPosition().x, getPosition().y);
		bullet->speed = shotSpeed;
		bullet->speedRate = shotSpeedRate;
		bullet->angle = shotAngle;
        bullet->setPosition(point);
        bullet->positionId = point.y/512;
        
        shotDelay = 5;
    }
    else
    {
        shotDelay--;
    }
}

Mover* Player::GetBullet()
{
    std::vector<Mover *>::iterator i;
    for (i = TaskManager::objectContainer.begin(); i != TaskManager::objectContainer.end(); ++i)
    {
        if ((*i)->isAlive == false)
        {
            (*i)->setVisible(true);
            (*i)->isAlive = true;
            return (*i);
        }
    }
    
    auto p_bullet = PlayerBullet::create(0, 0, 0, "enemy_bullet02.png");
    this->getScene()->addChild(p_bullet);
    TaskManager::objectContainer.push_back(p_bullet);
    
    return p_bullet;
}

void Player::Destroy()
{
    GameData::getInstance()->playerHp--;
    
    if (GameData::getInstance()->playerHp == 0) {
    }
    
    
    Mover::Destroy();
     
    // 無敵時間の間、自機が点滅します
    auto blink = cocos2d::Blink::create(1, 5);
        
    // アクションの実行
    this->runAction(cocos2d::Sequence::create(blink, NULL));
}
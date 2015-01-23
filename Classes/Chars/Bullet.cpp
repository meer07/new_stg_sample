#include "Bullet.h"
#include "TaskManager.h"
#include "GameData.h"

Bullet* Bullet::create(const float param[], std::string fileName)
{
    Bullet *bullet = new Bullet();
    bullet->speed = param[0];
    bullet->speedRate = param[1];
    bullet->angle = param[2];
    bullet->isAlive = true;
    bullet->setTag(3);
    
    if (bullet && bullet->initWithSpriteFrameName(fileName))
    {
        bullet->autorelease();
        bullet->retain();
        return bullet;
    }
    
    CC_SAFE_DELETE(bullet);
    return NULL;
}

void Bullet::Move()
{
    MoveBase();
    Collision();
}

void Bullet::Collision()
{
    cocos2d::Rect bulletrect = this->boundingBox();
    cocos2d::Rect playerrect = TaskManager::getInstance().player->boundingBox();
    
    if(bulletrect.intersectsRect(playerrect))
    {
        TaskManager::getInstance().player->Destroy();
        this->isAlive = false;
        //std::cout << "Miss!!" << std::endl;
    }
}
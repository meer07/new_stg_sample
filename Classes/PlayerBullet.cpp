#include "PlayerBullet.h"
#include "TaskManager.h"
#include <iostream>

PlayerBullet* PlayerBullet::create(float speed, float speedRate, float angle, std::string fileName)
{
    PlayerBullet *bullet = new PlayerBullet();
    bullet->speed = speed;
    bullet->speedRate = speedRate;
    bullet->angle = angle;
    bullet->isAlive = true;
    bullet->setTag(2);
    
    if (bullet && bullet->initWithSpriteFrameName(fileName))
    {
        bullet->autorelease();
        bullet->retain();
        return bullet;
    }
    
    CC_SAFE_DELETE(bullet);
    return NULL;
}

void PlayerBullet::Move()
{
    MoveBase();
    Collision();
}

void PlayerBullet::Collision()
{
    std::vector<Mover *>::iterator i;
    for(i = TaskManager::objectContainer.begin(); i != TaskManager::objectContainer.end(); ++i){
        //  エリアが一緒のときのみ衝突判定
        if ((*i)->positionId == this->positionId) {
            cocos2d::Rect bulletrect = this->boundingBox();
            cocos2d::Rect enemyrect = (*i)->boundingBox();
            
            // 自機の弾と敵との衝突判定
            if ((*i)->getTag() == 4 && bulletrect.intersectsRect(enemyrect))
            {
                (*i)->hitpoint--;
                
                // HPが0の時、生存フラグを下ろす。
                if ((*i)->hitpoint < 0)
                {
                    (*i)->Destroy();
                }
                this->isAlive = false;
            }
        }
    }
}

PlayerBullet::~PlayerBullet()
{
    std::cout << "delete" << std::endl;
}
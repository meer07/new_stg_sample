#include "Mover.h"
#include <math.h>
#include "EffectManager.h"

// 共通の移動処理
void Mover::MoveBase()
{
    cocos2d::Size windowSize = cocos2d::Director::getInstance()->getWinSize();
    
    // 角度をラジアンに変える
    float rad = CC_DEGREES_TO_RADIANS(angle);
    
    // 現在の座標を取得して角度と速度に合わせて移動
    cocos2d::Vec2 position = this->getPosition();
    speed += speedRate;
    this->setPosition(position.x + speed*cosf(rad), position.y + speed*sinf(rad));
    
    // 画面外に出たら生存フラグを下ろす。
    if (this->getPosition().x > windowSize.width+10 || this->getPosition().y > windowSize.height+10
        || this->getPosition().x < -10 || this->getPosition().y < -10)
    {
        isAlive = false;
    }
}

void Mover::Destroy()
{
    this->isAlive = false;
    
    cocos2d::Sprite *bom = cocos2d::Sprite::create();
    bom->setPosition(this->getPosition());
    this->getScene()->addChild(bom);
    
    cocos2d::Animate *animate = EffectManager::getInstance().DestroyEffect();
    
    // 爆発の終わりに生存フラグを下ろす
    cocos2d::CallFunc *func = cocos2d::CallFunc::create([this, bom](){
        bom->getScene()->removeChild(bom);
    });
    
    bom->runAction(cocos2d::Sequence::create(animate, func, NULL));
    //bom->runAction(animate);
}
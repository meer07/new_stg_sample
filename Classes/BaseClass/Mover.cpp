//
//  Mover.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#include "Mover.h"

// 共通の移動処理
void Mover::MoveBase()
{
    cocos2d::Size windowSize = cocos2d::Director::getInstance()->getWinSize();
    
    // 角度をラジアンに変える
    float rad = CC_DEGREES_TO_RADIANS(angle);
    
    // 現在の座標を取得して角度と速度に合わせて移動
    cocos2d::Vec2 position = this->getPosition();
    this->setPosition(position.x + speed*cosf(rad), position.y + speed*sinf(rad));
    
    // 画面外に出たら生存フラグを下ろす。
    if (this->getPosition().x > windowSize.width+10 || this->getPosition().y > windowSize.height+10
        || this->getPosition().x < -10 || this->getPosition().y < -10)
    {
        isAlive = false;
    }
}
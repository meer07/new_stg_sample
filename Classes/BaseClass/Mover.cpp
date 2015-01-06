//
//  Mover.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#include "Mover.h"

// 共通の移動処理
void Mover::MoveBase(){
    Size windowSize = Director::getInstance()->getWinSize();
    
    // 角度をラジアンに変える
    float rad = CC_DEGREES_TO_RADIANS(angle);
    
    // 現在の座標を取得して角度と速度に合わせて移動
    Vec2 position = this->getPosition();
    this->setPosition(position.x + speed*cosf(rad), position.y + speed*sinf(rad));
    
    // 画面外に出たら生存フラグを下ろす。
    if (this->getPosition().x > windowSize.width || this->getPosition().y > windowSize.height
        || this->getPosition().x < 0 || this->getPosition().y < 0) {
        isAlive = false;
    }
}
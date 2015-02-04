//
//  EnemyPattern.cpp
//  SimpleSTG
//
//  Created by 海下 直哉 on 2015/02/04.
//
//

#include "EnemyPattern.h"

void EnemyPattern::MakePattern(Mover &mover, const float enemyParam[], cocos2d::Point postion)
{
    mover.setPosition(postion);
    mover.speed = enemyParam[0];
    mover.speedRate = enemyParam[1];
    mover.angle = enemyParam[2];
}
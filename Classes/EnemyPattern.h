//
//  EnemyPattern.h
//  SimpleSTG
//
//  Created by 海下 直哉 on 2015/02/04.
//
//
#pragma once
#include <cocos2d.h>
#include "Mover.h"

class EnemyPattern
{
public:
    void MakePattern(Mover &mover, const float enemyParam[], cocos2d::Point postion);
};
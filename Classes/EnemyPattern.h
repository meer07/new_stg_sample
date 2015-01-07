//
//  EnemyPattern.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/07.
//
//

#ifndef __Getsuyoubi__EnemyPattern__
#define __Getsuyoubi__EnemyPattern__

#include <stdio.h>
#include "TaskManager.h"
#include "Enemy01.h"
#include "Enemy02.h"

class EnemyPattern
{
public:
    void EnemyPattern01(float param[], int limit, float makePointY);
    void EnemyPattern02(float param[], int limit, float makePointY);
    void EnemyPattern03();
};
#endif /* defined(__Getsuyoubi__EnemyPattern__) */

//
//  Enemy02.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/07.
//
//

#ifndef __Getsuyoubi__Enemy02__
#define __Getsuyoubi__Enemy02__

#include "Enemy.h"

class Enemy02 : public Enemy
{
public:
    static Enemy02* create(const float enemyParam[], const float shotParam[],std::string fileName);
    void MovePattern();
    void Move();
    void Shot();
    void Destroy();
};

#endif /* defined(__Getsuyoubi__Enemy02__) */

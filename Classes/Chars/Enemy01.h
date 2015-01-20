//
//  Enemy01.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/06.
//
//

#ifndef __Getsuyoubi__Enemy01__
#define __Getsuyoubi__Enemy01__

#include "Enemy.h"

class Enemy01 : public Enemy
{
public:
    static Enemy01* create(const float enemyParam[], const float shotParam[],std::string fileName);
    void MovePattern();
    void Move();
    void Shot();
    void Destroy();
};

#endif /* defined(__Getsuyoubi__Enemy01__) */

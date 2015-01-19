//
//  EnemyPattern.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/07.
//
//

#ifndef __Getsuyoubi__EnemyPattern__
#define __Getsuyoubi__EnemyPattern__

#include <cocos2d.h>

class EnemyPattern
{
public:
    void EnemyPattern01(const float enemyParam[], const float shotParam[], float makePointY);
    void EnemyPattern02(const float enemyParam[], const float shotParam[], float makePointY);
    void EnemyPattern03(const float enemyParam[], const float shotParam[], float makePointX);
    void EnemyPattern04(const float enemyParam[], const float shotParam[], float makePointX);
    void EnemyPattern05(const float enemyParam[], const float shotParam[], float makePointX);
    void EnemyPattern06(const float enemyParam[], const float shotParam[], float makePointX);
    void EnemyPattern07(const float enemyParam[], const float shotParam[], float makePointY);
    void EnemyPattern08(const float enemyParam[], const float shotParam[], float makePointY);
};
#endif /* defined(__Getsuyoubi__EnemyPattern__) */

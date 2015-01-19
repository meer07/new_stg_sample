//
//  Boss02.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/16.
//
//

#ifndef __Getsuyoubi__Boss02__
#define __Getsuyoubi__Boss02__

#include "Enemy.h"

class Boss02 : public Enemy
{
public:
    static Boss02* create(std::string fileName);
    void MovePattern(cocos2d::Point nowPoint);
    void Move();
    void Shot();
private:
    float bulletAngle;
    bool moveFlag;
    bool shotFlag;
    void MainShot(float shotAngle[], float shotSpeed, int way, std::string fileName);
    void ShotPattern(float angle, float shotSpeed, std::string fileName);
    float MakeAngle();
};


#endif /* defined(__Getsuyoubi__Boss02__) */

//
//  Boss01.h
//  Getsuyoubi
//
//  Created by 海下直哉 on 2015/01/12.
//
//

#ifndef __Getsuyoubi__Boss01__
#define __Getsuyoubi__Boss01__

#include <stdio.h>
#include "Enemy.h"

class Boss01 : public Enemy
{
public:
    
    static Boss01* create(std::string fileName);
    void MovePattern();
    void Move();
    void Shot();
private:
    bool moveFlag;
    bool shotFlag;
    void MainShot(float baseAngle);
    void RotateShot(float angle);
};

#endif /* defined(__Getsuyoubi__Boss01__) */

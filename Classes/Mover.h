//
//  Mover.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#ifndef __Getsuyoubi__Mover__
#define __Getsuyoubi__Mover__

#include <math.h>

class Mover : public cocos2d::Sprite
{
public:
    int score;
    int hitpoint;
    float speed;
    float speedRate;
    float angle;
    bool isAlive;
    //Layer *sceneLayer;
    
    // 仮想メソッド
    virtual void MovePattern(){};
    virtual void Move(){};
    virtual void Collision(){};
    
protected:
    void MoveBase();
};
#endif /* defined(__Getsuyoubi__Mover__) */

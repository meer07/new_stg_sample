//
//  Mover.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/05.
//
//

#ifndef __Getsuyoubi__Mover__
#define __Getsuyoubi__Mover__

#include <stdio.h>
using namespace cocos2d;

class Mover : public Sprite{
public:
    float speed;
    float speedRate;
    float angle;
    int placeID;
    bool isAlive;
    //Layer *sceneLayer;
    
    // 仮想メソッド
    virtual void Move(){};
    virtual void Collision(){};
    
protected:
    void MoveBase();
};
#endif /* defined(__Getsuyoubi__Mover__) */

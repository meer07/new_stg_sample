//
//  BackGround.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/16.
//
//

#ifndef __Getsuyoubi__BackGround__
#define __Getsuyoubi__BackGround__

#include <cocos2d.h>

class BackGround : public cocos2d::Sprite {
public:
    BackGround(cocos2d::Size windowSize_, cocos2d::Layer &sceneLayer);
    ~BackGround();
    Sprite *backGround_f;
    Sprite *backGround_b;
    void Move(float speedRate);
    
private:
    cocos2d::Size windowSize;
};

#endif /* defined(__Getsuyoubi__BackGround__) */

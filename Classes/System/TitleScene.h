//
//  TitleScene.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/20.
//
//

#ifndef __Getsuyoubi__TitleScene__
#define __Getsuyoubi__TitleScene__

#include <cocos2d.h>

class TitleScene : cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TitleScene);
    
private:
    void gameStart();
};
#endif /* defined(__Getsuyoubi__TitleScene__) */

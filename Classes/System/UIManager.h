//
//  UIManager.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/20.
//
//

#ifndef __Getsuyoubi__UIManager__
#define __Getsuyoubi__UIManager__

#include <cocos2d.h>

class UIManager {
public:
    cocos2d::Node *sceneNode;
    cocos2d::Label *score, *zanki;
    
    UIManager();
    ~UIManager();
    void setTitleScene(cocos2d::Layer& sceneLayer);
    void setGameScene(cocos2d::Layer& sceneLayer);
    void updateUI();
};

#endif /* defined(__Getsuyoubi__UIManager__) */

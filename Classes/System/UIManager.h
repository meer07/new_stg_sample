//
//  UIManager.h
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/14.
//
//

#ifndef __Getsuyoubi__UIManager__
#define __Getsuyoubi__UIManager__

class UIManager {
public:
    UIManager();
    ~UIManager();
    void ShowScore(cocos2d::Size windowSize, cocos2d::Layer &sceneLayer);
    void UpDate();
private:
    cocos2d::Label *scoreLabel;
};

#endif /* defined(__Getsuyoubi__UIManager__) */

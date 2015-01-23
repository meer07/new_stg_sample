#pragma once
#include <cocos2d.h>

class UIManager {
public:
    static UIManager& getIncetance();
    
    UIManager();
    UIManager(const UIManager &other){};
    UIManager &operator=(const UIManager &other){};
    ~UIManager();
    void setTitleScene(cocos2d::Layer& sceneLayer);
    void setGameScene(cocos2d::Layer& sceneLayer);
    void updateUI();
    void setLevelLabel(const int level, cocos2d::Layer& sceneLayer);
private:
    cocos2d::Node *sceneNode;
    cocos2d::Label *score, *zanki;
};

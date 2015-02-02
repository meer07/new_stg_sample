#pragma once
#include <cocos2d.h>

class UIManager {
public:
    static UIManager& getIncetance();
    UIManager(const UIManager &other) = delete;
    UIManager &operator=(const UIManager &other) = delete;
    
    void SetTitleScene(cocos2d::Layer& sceneLayer);
    void SetGameScene(cocos2d::Layer& sceneLayer);
    void UpdateUI();
    void SetLevelLabel(const int level);
	void SetClearLabel();
    void SetGameOver();

private:
    UIManager(){};
    ~UIManager(){};
    cocos2d::Node *sceneNode;
    cocos2d::Label *score, *zanki;
};

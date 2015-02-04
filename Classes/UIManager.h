#pragma once
#include <cocos2d.h>

class UIManager {
public:
    static UIManager& getIncetance();
    UIManager(const UIManager &other) = delete;
    UIManager &operator=(const UIManager &other) = delete;
    
    void SetTitleScene(cocos2d::Layer& sceneLayer);
    void SetGameScene(cocos2d::Layer& sceneLayer);
    void SetLevelLabel(const int level, cocos2d::Layer& sceneLayer);
	void SetClearLabel(cocos2d::Layer& sceneLayer);
    void SetGameOver(cocos2d::Layer& sceneLayer);
    void UpdateUI();

private:
    UIManager(){};
    ~UIManager(){};
    cocos2d::Label *score, *zanki;
};

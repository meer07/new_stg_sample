#pragma once
#include <cocos2d.h>

class EffectManager {
public:
    static EffectManager& getInstance();
    EffectManager(const EffectManager &other) = delete;
    EffectManager &operator=(const EffectManager &other) = delete;
    
    cocos2d::Animate* DestroyEffect();
private:
    EffectManager(){};
    ~EffectManager(){};
};
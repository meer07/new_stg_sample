#pragma once
#include <cocos2d.h>

class EffectManager {
public:
    static EffectManager& getInstance();
    EffectManager();
    EffectManager(const EffectManager &other){}
    EffectManager &operator=(const EffectManager &other){}
    ~EffectManager();
    
    cocos2d::Animate* DestroyEffect();
};
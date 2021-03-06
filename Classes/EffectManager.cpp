﻿#include "EffectManager.h"
#include <string>

EffectManager& EffectManager::getInstance()
{
    static EffectManager instance;
    return instance;
}

cocos2d::Animate* EffectManager::DestroyEffect()
{
    cocos2d::Vector<cocos2d::SpriteFrame *> animframes(8);
    
    for (int i = 1; i <= 8; i++) {
        auto str = cocos2d::__String::createWithFormat("bom0%i.png", i);
        auto frame = cocos2d::SpriteFrameCache::getInstance()->getSpriteFrameByName(str->getCString());
        animframes.pushBack(frame);
    }
    
    auto animation = cocos2d::Animation::createWithSpriteFrames(animframes, 0.05f);
    return cocos2d::Animate::create(animation);
}
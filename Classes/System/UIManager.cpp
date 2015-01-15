//
//  UIManager.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/14.
//
//

#include "UIManager.h"
#include "GameData.h"
#include <iostream>
#include <string>

UIManager::UIManager()
{
}

void UIManager::ShowScore(cocos2d::Size windowSize, cocos2d::Layer &sceneLayer)
{
    std::string scoreText = std::to_string(GameData::getInstance().score);
    scoreLabel = cocos2d::Label::createWithTTF(scoreText, "/Users/708kaige/Desktop/Getsuyoubi/Resources/fonts/PixelMplus12-Regular.ttf", 32);
    scoreLabel->setPosition(100, windowSize.height-30);
    sceneLayer.addChild(scoreLabel);
}

void UIManager::UpDate()
{
    scoreLabel->setString(std::to_string(GameData::getInstance().score));
}


UIManager::~UIManager()
{
}
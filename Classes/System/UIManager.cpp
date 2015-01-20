//
//  UIManager.cpp
//  Getsuyoubi
//
//  Created by 海下 直哉 on 2015/01/20.
//
//

#include "UIManager.h"
#include "GameData.h"
#include "../cocos2d/cocos/editor-support/cocostudio/CocoStudio.h"
#include <string>

UIManager::UIManager()
{
}

void UIManager::setTitleScene(cocos2d::Layer& sceneLayer)
{
    std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("titlescene.csb");
    sceneNode = cocos2d::CSLoader::getInstance()->createNodeWithFlatBuffersFile(fullpath);
    sceneLayer.addChild(sceneNode);
}

void UIManager::setGameScene(cocos2d::Layer& sceneLayer)
{
    cocos2d::Size windowSize = cocos2d::Director::getInstance()->getWinSize();
    std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("PixelMplus12-Bold.ttf");
    score = cocos2d::Label::createWithTTF("score:\n" + std::to_string(GameData::getInstance().score),
                                          fullpath,
                                          32);
    zanki = cocos2d::Label::createWithTTF(std::to_string(GameData::getInstance().playerHp),
                                          fullpath,
                                          32);
    
    score->setPosition(100, windowSize.height-50);
    zanki->setPosition(windowSize.width-50, windowSize.height-50);
    sceneLayer.addChild(score);
    sceneLayer.addChild(zanki);
}

void UIManager::updateUI()
{
    score->setString("score:\n" + std::to_string(GameData::getInstance().score));
    zanki->setString(std::to_string(GameData::getInstance().playerHp));
}

UIManager::~UIManager()
{
    sceneNode = NULL;
    CC_SAFE_RELEASE(sceneNode);
}
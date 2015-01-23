#include "UIManager.h"
#include "GameData.h"
#include "TaskManager.h"
#include "../cocos2d/cocos/editor-support/cocostudio/CocoStudio.h"
#include <string>

UIManager& UIManager::getIncetance()
{
    static UIManager instance;
    return instance;
}

UIManager::UIManager()
{
}

void UIManager::setTitleScene(cocos2d::Layer& sceneLayer)
{
    cocos2d::CSLoader::getInstance()->setRecordJsonPath(true);
    std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("titlescene.csb");
    sceneNode = cocos2d::CSLoader::getInstance()->createNodeWithFlatBuffersFile("/Users/naoya-kaige/Desktop/SimpleSTG/Resources/titlescene.csb");
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

void UIManager::setLevelLabel(const int level, cocos2d::Layer& sceneLayer)
{
    cocos2d::Size windowSize = cocos2d::Director::getInstance()->getWinSize();
    std::string fullPath = cocos2d::FileUtils::getInstance()->fullPathForFilename("PixelMplus12-Bold.ttf");
    std::string labelText = "Level " + std::to_string(level);
    
    auto levelLabel = cocos2d::Label::createWithTTF(labelText, fullPath, 72);
    levelLabel->setPosition(windowSize.width/2, windowSize.height/2);
    sceneLayer.addChild(levelLabel);
    
    cocos2d::CallFunc *func = cocos2d::CallFunc::create([this, levelLabel](){
        //levelLabel->getScene()->removeChild(levelLabel);
        TaskManager::getInstance().sceneLayer->removeChild(levelLabel);
    });

    levelLabel->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(5), func ,NULL));
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
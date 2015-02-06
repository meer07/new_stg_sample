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

// タイトルのシーンを設定
void UIManager::SetTitleScene(cocos2d::Scene& sceneLayer)
{
    cocos2d::CSLoader::getInstance()->setRecordJsonPath(true);
    std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("TitleScene.csb");
    cocos2d::Node *sceneNode = cocos2d::CSLoader::getInstance()->createNodeWithFlatBuffersFile(fullpath);
    sceneLayer.addChild(sceneNode);
}

// ゲーム本編のUI(スコアと残機)を設定
void UIManager::SetGameScene(cocos2d::Scene& sceneLayer)
{
    cocos2d::Size windowSize = cocos2d::Director::getInstance()->getWinSize();
    std::string fullpath = cocos2d::FileUtils::getInstance()->fullPathForFilename("PixelMplus12-Bold.ttf");
    score = cocos2d::Label::createWithTTF("score:\n" + std::to_string(GameData::getInstance()->score),
                                          fullpath,
                                          32);
    zanki = cocos2d::Label::createWithTTF(std::to_string(GameData::getInstance()->playerHp),
                                          fullpath,
                                          32);
    
    score->setPosition(100, windowSize.height-50);
    zanki->setPosition(windowSize.width-50, windowSize.height-50);
    sceneLayer.addChild(score);
    sceneLayer.addChild(zanki);
}

// ステージの最初に何面か表示する
void UIManager::SetLevelLabel(const int level, cocos2d::Scene& sceneLayer)
{
    cocos2d::Size windowSize = cocos2d::Director::getInstance()->getWinSize();
    std::string fullPath = cocos2d::FileUtils::getInstance()->fullPathForFilename("PixelMplus12-Bold.ttf");
    std::string labelText = "Level " + std::to_string(level);
    
    auto levelLabel = cocos2d::Label::createWithTTF(labelText, fullPath, 72);
    levelLabel->setPosition(windowSize.width/2, windowSize.height/2);
	sceneLayer.addChild(levelLabel);
    
    cocos2d::CallFunc *func = cocos2d::CallFunc::create([this, levelLabel, &sceneLayer](){
        sceneLayer.removeChild(levelLabel);
    });

    levelLabel->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(5), func ,NULL));
}

// ゲーム全てクリアしたことを表示する
void UIManager::SetClearLabel(cocos2d::Scene& sceneLayer)
{
	cocos2d::Size windowSize = cocos2d::Director::getInstance()->getWinSize();
	std::string fullPath = cocos2d::FileUtils::getInstance()->fullPathForFilename("PixelMplus12-Bold.ttf");
	std::string labelText = "Mission Completed\nThank you for Playing!!";

	auto label = cocos2d::Label::createWithTTF(labelText, fullPath, 72);
	label->setPosition(windowSize.width / 2, windowSize.height / 2);
	sceneLayer.addChild(label);

	cocos2d::CallFunc *func = cocos2d::CallFunc::create([this, label, &sceneLayer](){
		sceneLayer.removeChild(label);
	});

	cocos2d::CallFunc *end = cocos2d::CallFunc::create([this, label, &sceneLayer](){
		sceneLayer.removeChild(label);
	});

	label->runAction(cocos2d::Sequence::create(cocos2d::DelayTime::create(10), func, end, NULL));
}

void UIManager::SetGameOver(cocos2d::Scene& sceneLayer)
{
    cocos2d::Size windowSize = cocos2d::Director::getInstance()->getWinSize();
    std::string fullPath = cocos2d::FileUtils::getInstance()->fullPathForFilename("PixelMplus12-Bold.ttf");
    std::string labelText = "Game Over";
    
    auto label = cocos2d::Label::createWithTTF(labelText, fullPath, 72);
    label->setPosition(windowSize.width / 2, windowSize.height / 2);
    sceneLayer.addChild(label);
}

// スコアと残機の表示を更新
void UIManager::UpdateUI()
{
    score->setString("score:\n" + std::to_string(GameData::getInstance()->score));
    zanki->setString(std::to_string(GameData::getInstance()->playerHp));
}